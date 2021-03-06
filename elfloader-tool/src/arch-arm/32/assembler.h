/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * This software may be distributed and modified according to the terms of
 * the GNU General Public License version 2. Note that NO WARRANTY is provided.
 * See "LICENSE_GPLv2.txt" for details.
 *
 * @TAG(GD_GPL)
 */

#ifndef __ASSEMBLER_32_H__
#define __ASSEMBLER_32_H__

/* This file contains useful macros for assembly code. */

#ifdef __ASSEMBLER__

#define      SCTLR(reg)    p15, 0, reg, c1, c0, 0
#define      CLIDR(reg)    p15, 1, reg, c0, c0, 1
#define      TTBR0(reg)    p15, 0, reg, c2, c0, 0
#define      TTBCR(reg)    p15, 0, reg, c2, c0, 2
#define       DACR(reg)    p15, 0, reg, c3, c0, 0
#define     BPIALL(reg)    p15, 0, reg, c7, c5, 6
#define    TLBIALL(reg)    p15, 0, reg, c8, c7, 0
#define CONTEXTIDR(reg)    p15, 0, reg, c13, c0, 1

/* Processor mode encodings */
#define PMODE_USER          0x10
#define PMODE_FIQ           0x11
#define PMODE_IRQ           0x12
#define PMODE_SUPERVISOR    0x13
#define PMODE_ABORT         0x17
#define PMODE_UNDEFINED     0x1b
#define PMODE_SYSTEM        0x1f

/* Processor exception mask bits */
#define PMASK_ASYNC_ABORT   (1 << 8)
#define PMASK_IRQ           (1 << 7)
#define PMASK_FIRQ          (1 << 6)

#else /* !__ASSEMBLER__ */
#warning "Including assembly-specific header in C code"
#endif

#endif /* __ASSEMBLER_H_32__ */
