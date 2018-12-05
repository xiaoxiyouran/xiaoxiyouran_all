;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; Copyright ARM Ltd 1999. All rights reserved.
;
; This module performs ROM/RAM remapping (if required), initializes stack pointers and
; interrupts for each mode, and finally branches to __main in the C library (which
; eventually calls main()).
;
; On reset, the ARM core starts up in Supervisor (SVC) mode, in ARM state, with IRQ and FIQ disabled.
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; ----------------------------------------------------------------------------
;;  Copyright (c) 2010-2011 by Carbon Design Systems, Inc., All Rights Reserved.
;;
;;  THIS SOFTWARE CONTAINS CONFIDENTIAL INFORMATION AND TRADE SECRETS OF CARBON
;;  DESIGN SYSTEMS, INC.  PERMISSION IS HEREBY GRANTED TO USE, MODIFY, AND/OR COPY
;;  THIS SOFTWARE FOR INTERNAL USE ONLY PROVIDED THAT THE ABOVE COPYRIGHT NOTICE
;;  APPEARS IN ALL COPIES OF THIS SOFTWARE.
;; ----------------------------------------------------------------------------

        AREA    Init, CODE, READONLY

; --- Standard definitions of mode bits and interrupt (I & F) flags in PSRs

Mode_USR        EQU     0x10
Mode_FIQ        EQU     0x11
Mode_IRQ        EQU     0x12
Mode_SVC        EQU     0x13
Mode_ABT        EQU     0x17
Mode_UNDEF      EQU     0x1B
Mode_SYS        EQU     0x1F ; available on ARM Arch 4 and later

I_Bit           EQU     0x80 ; when I bit is set, IRQ is disabled
F_Bit           EQU     0x40 ; when F bit is set, FIQ is disabled


memmap_cfg_reg  EQU     0xA0003000
memmap_ctr_reg  EQU     0xA0003004

memctl_smtmgr_set0 EQU  0xB0005094
memctl_smtmgr_set1 EQU  0xB0005098
memctl_smtmgr_set2 EQU  0xB000509C


; --- System memory locations

        ENTRY

; --- Set up if ROM/RAM remapping required
                GBLL ROM_RAM_REMAP
ROM_RAM_REMAP   SETL {TRUE} ; change to {FALSE} if remapping not required

; --- Perform ROM/RAM remapping, if required
    IF :DEF: ROM_RAM_REMAP

; On reset, an aliased copy of ROM is at 0x0.
; Continue execution from 'real' ROM rather than aliased copy
        LDR     pc, =Instruct_2
                                     
Instruct_2        
; Remap by setting Remap bit of the CM_ctl register
        LDR     r1, =memmap_cfg_reg
        LDR     r0, [r1]
        ORR     r0, r0, #1
        STR     r0, [r1]
                                                                     

        LDR     r1, =memmap_ctr_reg
        LDR     r0, [r1]
        ORR     r0, r0, #1
        STR     r0, [r1]

; RAM is now at 0x0.
; The exception vectors (in vectors.s) must be copied from ROM to the RAM
; The copying is done later by the C library code inside __main

    ENDIF

        EXPORT  Reset_Handler

Reset_Handler
; --- Initialize R0~R9, that is just for verification to clear the 'X' on the amba bus   
        MOV R0,#0 
        MOV R1,#0 
        MOV R2,#0 
        MOV R3,#0 
        MOV R4,#0 
        MOV R5,#0 
        MOV R6,#0 
        MOV R7,#0 
        MOV R8,#0 
        MOV R9,#0 
        MOV R10,#0 
        MOV R11,#0 
        MOV R12,#0 

; --- Initialise stack pointer registers
; Enter SVC mode and set up the SVC stack pointer
        IMPORT ||Image$$SYS_STACK$$Base||
        MSR     CPSR_c, #Mode_SVC:OR:I_Bit:OR:F_Bit ; No interrupts
        LDR     SP, =||Image$$SYS_STACK$$Base||

; Enter IRQ mode and set up the IRQ stack pointer
        IMPORT ||Image$$IRQ_STACK$$Base||
        MSR     CPSR_c, #Mode_IRQ:OR:I_Bit:OR:F_Bit ; No interrupts
        LDR     SP, =||Image$$IRQ_STACK$$Base||     ; Set up IRQ mode stack
        MSR     CPSR_c, #Mode_SVC:OR:F_Bit          ; Back to SVC mode with IRQ enabled



; Set up other stack pointers if necessary
        ; ...

; --- Initialise memory system
; Opt Flash read cycles(t_rc)     
        LDR     r1, =memctl_smtmgr_set0
        LDR     r0, [r1]
        AND     r0, r0, #0xFFFFFFC0 
        ORR     r0, r0, #0x15
        STR     r0, [r1]


; Opt ext sram read and write cycles(t_rc and t_wp)     
        LDR     r1, =memctl_smtmgr_set1
        LDR     r0, [r1]
        AND     r0, r0, #0xFFFFFFC0 
        ORR     r0, r0, #2
        STR     r0, [r1]

        AND     r0, r0, #0xFFFF03FF
        ORR     r0, r0, #0x0800
        STR     r0, [r1]


;/****************************************/
; --- Initialise DDR CONTROLLER
;/****************************************/
;1> ;ddr2 SDRAM Initialization 
;ddr2 EMR2
    ldr    r0,=0xb00061f8
    ldr    r1,=0x80              
    ldr    r2,[r0]
    orr    r2,r2,r1
    str    r2,[r0]

;ddr2 EMR1 Enable_dll with Set additive Latency
   ldr    r0,=0xb00061f4
   ldr    r1,=0xffffffc6
   ldr    r2,[r0]
   and r2,r2,r1
   str    r2,[r0]

;ddr2 MR0  burst length=4 sequential  DLL_reset
   ldr    r0,=0xb00061f0
   ldr    r1,=0xb52
   ldr    r2,[r0]
   orr    r2,r2,r1
   ldr r1,=0xfffffb52
   and r2,r2,r1
   str    r2,[r0]
    
;CCR triggle SDRAM initial
   ldr    r0,=0xb0006000
   ldr    r1,=0x80000000
   ldr    r2,[r0]
   orr    r2,r2,r1
   str    r2,[r0]

    ldr r0,=0x0100        ;simulation-only, 54us when 400Mhz
loopij
    sub    r0,r0,#0x1        
    cmp r0,#0x0        
    bne    loopij    
    
;IOCR open ODT  both DQ and DQS
;IOCR
    ldr    r1, =0xb0006008     ;open ODT
    ldr    r0, =0xc000003
    str    r0, [r1]

;ODTCR 
    ldr    r1, =0xb0006098     ;ODT write&read
    ldr    r0, =0x84218421
    str    r0, [r1]

;ZQCR0  
    ldr    r1, =0xb00060a8     ;ODT
    ldr    r0, =0x100085ef
    str    r0, [r1]

;CCR: enable host-port, bit17=DFTCMP=1
    ldr     r0, =0xb0006000
    ldr     r1, =0x00020104
    str     r1, [r0]

;DCR external-ddr-capacity
    ldr     r0, =0xb0006004
    ldr     r1, =0x000041b4        ;4*512Mbx8
    str     r1, [r0]
     
;DO_INIT, bit24
    ldr     r0, =0xb0006004
    ldr     r1, [r0]
    orr     r1, r1, #0x1000000
    str     r1, [r0]

;TPR3 CL : timing parameters, burst length=4
    ldr r1,=0xb000601c    
    ldr r0,=0x19a1    
    str r0,[r1]

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;  dll reset
;waite delay 3f000*(cmpsub cycle)
    ;ldr   r3,  =0x3f000
    ldr   r3,  =0x00100 ;simulation only
datatraining_loop_s
    sub     r3,  r3,  #1
    ;cmpsub.a     r3,  #1
    cmp     r3,  #1
    bne    datatraining_loop_s

;dll RESET begin 
;ddr2_phy_ctrl bit[20:16]=dll_srst_b=0, reset
    ldr r0,=0xa0003020    
    ldr r1, [r0]
    ldr r2, =0xffe0ffff
    and r1, r1, r2
    str r1,[r0]

;waite delay 3f000*(sub-cmd cycle)
    ;ldr   r3,  =0x3f000
    ldr   r3,  =0x00100 ;simulation only
datatraining_loop_sf
    sub     r3,  r3,  #1
    cmp     r3,  #1
    bne    datatraining_loop_sf

;dll RESET end
    orr r1, r1, #0x001f0000
    str r1, [r0]

ddr_loop
    ldr     r0, =0xb00063fc
    ldr     r1, [r0]
    and     r1, r1, #1
    cmp     r1, #1
    beq     ddr_loop

;Turn off refresh
    ldr     r0, =0xb0006010
    ldr     r1, [r0]
    orr     r1, r1, #0x80000000
    str     r1, [r0]

;waite delay 3f000*(sub-cmd cycle)
    ;ldr   r3,  =0x3f000
    ldr   r3,  =0x00100 ;simulation only
datatraining_loop_sff
    sub     r3,  r3,  #1
    cmp     r3,  #1
    bne    datatraining_loop_sff

;disable host-port, enable DT-traing, DQS Drift limit=clk_90
back_datatraining
    ;mov.a   r9,  #0
    ldr   r9, =0x0
    ldr   r0, =0xb0006000
    ldr   r1, [r0]
    ldr   r2, =0x40020000
    orr   r1, r1, r2
    str   r1,[r0]
    
;waite delay 3f000*(sub-cmd cycle)
    ;ldr   r3,  =0x3f000
    ldr   r3,  =0x00100 ;simulation only
datatraining_loop
    sub     r3,  r3,  #1
    cmp     r3,  #1
    bne    datatraining_loop
    
;ddr2_status, not include in MCTL IP.  
;1> wait untile status[0]=0
ddr_datatraining_3fc
    ldr     r0, =0xb00063fc
    ldr     r1, [r0]
    and     r1, r1, #1
    cmp     r1, #1
    beq     ddr_datatraining_3fc

;2> if status[1]=1 then wrong,else goto training
    ldr     r0, =0xb00063fc
    ldr     r1, [r0]
    and     r1, r1, #2
    cmp     r1, #2
    beq    fcwrong
    bne    training 

fcwrong
    ;mov.a   r9,   #1    
    ldr   r9,  =0x1
    ldr   r1,=0x31000000
    ;mov.a r0,#0x66
    ldr   r0, =0x66
    str   r0,[r1]

;CSR : DT-traning status bit[20]
training   
    ldr    r0, =0xb000600c
    ldr    r1, [r0]
    ldr    r3, =0x100000
    and    r1, r1,r3
    cmp    r1, r3 
    bne    print
    ;b     error

print
;if status[1]=1=wrong, then goback DT,else enable host-port
    ;cmpsub.a    r9,  #1
    cmp    r9,  #1
    beq  back_datatraining

    ;mov.a  r9,  #0
    ldr   r9, =0x0
    ldr   r0, =0xb0006000
    ldr   r1, [r0]
    orr   r1, r1, #0x00000004
    str   r1, [r0]

;Turn on Refresh
    ldr     r0, =0xb0006010
    ldr     r1, [r0]
    and     r1, r1, #0x7fffffff
    str     r1, [r0]

; --- Initialise critical IO devices
        ; ...

; --- Initialise interrupt system variables here
        ; ...

;===================================================================
; Store address of branch to __main and enable MMU
;===================================================================

        IMPORT  __main                      ; before MMU enabled import label to __main
        LDR     r12,=__main                 ; save this in register for possible long jump


        BX      r12                         ; branch to __main  C library entry point

        LTORG

        END                                 ; mark the end of this file

        ; End of File Init.s

