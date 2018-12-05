//-----------------------------------------------------------------------------
// The confidential and proprietary information contained in this file may
// only be used by a person authorised under and to the extent permitted
// by a subsisting licensing agreement from ARM Limited.
//
//            (C) COPYRIGHT 1994-2007 ARM Limited.
//                ALL RIGHTS RESERVED
//
// This entire notice must be reproduced on all copies of this file
// and copies of this file may only be made by a person if such person is
// permitted to do so under the terms of a subsisting license agreement
// from ARM Limited.
//-----------------------------------------------------------------------------

/*-----------------------------------------------------------------------------
// Copyright (c) 2010-2011 by Carbon Design Systems, Inc., All Rights Reserved.
//
// THIS SOFTWARE CONTAINS CONFIDENTIAL INFORMATION AND TRADE SECRETS OF CARBON
// DESIGN SYSTEMS, INC.  PERMISSION IS HEREBY GRANTED TO USE, MODIFY, AND/OR COPY
// THIS SOFTWARE FOR INTERNAL USE ONLY PROVIDED THAT THE ABOVE COPYRIGHT NOTICE
// APPEARS IN ALL COPIES OF THIS SOFTWARE.
//
//---------------------------------------------------------------------------*/

#include <stdio.h>
#include <rt_misc.h>

// Heap base from scatter file
extern int Image$$HEAP$$ZI$$Base;

// The application's Main function
extern int $Super$$main(char argc, char * argv[]);

/////////////////////////////////////////////////////////////////////////////
//
// This function is called at the end of the C library initialisation and
// before main. Its purpose is to do any further initialisation before the
// application start.
//
/////////////////////////////////////////////////////////////////////////////

int $Sub$$main(char argc, char * argv[])
{
  return $Super$$main(argc, argv); // calls the original function
}


/////////////////////////////////////////////////////////////////////////////
//
// This function re-implements the C Library semihosted function. The stack
// pointer has aready been set and is passed back to the funtion, The base of
// the heap is set from the scatter file.
//
/////////////////////////////////////////////////////////////////////////////

__value_in_regs struct __initial_stackheap __user_initial_stackheap(
        unsigned R0, unsigned SP, unsigned R2, unsigned SL)
{
    struct __initial_stackheap config;

    config.heap_base = (unsigned int)&Image$$HEAP$$ZI$$Base; // placed by scatterfile
    config.stack_base = SP;   // inherit SP from the execution environment

    return config;
}

// End of File retarget.c
