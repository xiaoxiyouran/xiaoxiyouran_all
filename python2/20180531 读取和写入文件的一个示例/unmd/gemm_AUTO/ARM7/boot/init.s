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

; --- System memory locations

        ENTRY

; --- Set up if ROM/RAM remapping required
                GBLL ROM_RAM_REMAP
;ROM_RAM_REMAP   SETL {TRUE} ; change to {FALSE} if remapping not required
ROM_RAM_REMAP   SETL {FALSE} ; change to {FALSE} if remapping not required

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
        ; ...

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

