;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; Copyright ARM Ltd 1999. All rights reserved.
;
; Where there is ROM fixed at 0x0 (build_b & build_c), these are hard-coded at 0x0.
; Where ROM/RAM remapping occurs (build_d), these are copied from ROM to RAM.
; The copying is done automatically by the C library code inside __main.
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

        AREA Vect, CODE, READONLY

; These are example exception vectors and exception handlers

; *****************
; Exception Vectors
; *****************

; Note: LDR PC instructions are used here because branch (B) instructions
; could not simply be copied (the branch offsets would be wrong).  Also,
; a branch instruction might not reach if the ROM is at an address >32MB).

        ENTRY

        LDR     PC, Reset_Addr
        LDR     PC, Undefined_Addr
        LDR     PC, SWI_Addr
        LDR     PC, Prefetch_Addr
        LDR     PC, Abort_Addr
        NOP                             ; Reserved vector
        LDR     PC, IRQ_Addr
        LDR     PC, FIQ_Addr

        IMPORT  IRQ_Handler             ; 
        IMPORT  FIQ_Handler             ; 
        IMPORT  Reset_Handler           ; In init.s

Reset_Addr      DCD     Reset_Handler
Undefined_Addr  DCD     Undefined_Handler
SWI_Addr        DCD     SWI_Handler
Prefetch_Addr   DCD     Prefetch_Handler
Abort_Addr      DCD     Abort_Handler
                DCD     0               ; Reserved vector
IRQ_Addr        DCD     IRQ_Handler
FIQ_Addr        DCD     FIQ_Handler


; ************************
; Exception Handlers
; ************************

; --- Set up if SWI_LOOP required
    GBLL SWI_FORCE_LOOP_EN
;SWI_FORCE_LOOP_EN   SETL {TRUE} ; change to {TRUE} if loop is required

angel_SWIreason_ReportException EQU 0x18
ADP_Stopped_ApplicationExit     EQU 0x20026
; The following dummy handlers do not do anything useful in this example.
; They are set up here for completeness.

Undefined_Handler
        SUBS    PC, R14, #4     ; return
        NOP
SWI_Handler
        CMP     R0,#angel_SWIreason_ReportException
        BNE     NOTEXITSWI
        LDR     R0,=ADP_Stopped_ApplicationExit
        CMP     R1,R0
        BNE     NOTEXITSWI

    IF :DEF: SWI_FORCE_LOOP_EN
SWI_LOOP_0
        NOP
        NOP
        B       SWI_LOOP_0;
    ENDIF     
        LDR     PC, Reset_Addr

NOTEXITSWI
        SUBS    PC, R14, #0     ; return
        NOP
Prefetch_Handler
        SUBS    PC, R14, #4     ; return
        NOP
Abort_Handler
        SUBS    PC, R14, #4     ; return
        NOP

;FIQ_Handler
;        SUBS    PC, R14, #4     ; return
;        NOP
        END

