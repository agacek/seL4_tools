/*
 * Copyright 2014, NICTA
 *
 * This software may be distributed and modified according to the terms of
 * the GNU General Public License version 2. Note that NO WARRANTY is provided.
 * See "LICENSE_GPLv2.txt" for details.
 *
 * @TAG(NICTA_GPL)
 */

#ifndef _ELFLOADER_H_
#define _ELFLOADER_H_

#include "stdint.h"

typedef uintptr_t paddr_t;
typedef uintptr_t vaddr_t;

#define PAGE_BITS           12

#define BIT(x)              (1 << (x))
#define MASK(n)             (BIT(n) - 1)
#define MIN(a, b)           (((a) < (b)) ? (a) : (b))
#define IS_ALIGNED(n, b)    (!((n) & MASK(b)))
#define ROUND_UP(n, b)      (((((n) - 1) >> (b)) + 1) << (b))

#define ALIGN(n)            __attribute__((__aligned__(n)))


/*
 * Information about an image we are loading.
 */
struct image_info {
    /* Start/end byte of the image in physical memory. */
    paddr_t phys_region_start;
    paddr_t phys_region_end;

    /* Start/end byte in virtual memory the image requires to be located. */
    vaddr_t virt_region_start;
    vaddr_t virt_region_end;

    /* Virtual address of the user image's entry point. */
    vaddr_t  virt_entry;

    /*
     * Offset between the physical/virtual addresses of the image.
     *
     * In particular:
     *
     *  virtual_address + phys_virt_offset = physical_address
     */
    uint32_t phys_virt_offset;
};

/* Enable the mmu. */
extern void arm_enable_mmu(void);
extern void arm_enable_hyp_mmu(void);

/* Symbols defined in linker scripts. */
extern char _start[];
extern char _end[];
extern char _archive_start[];
extern char _archive_end[];

/* Load images. */
void load_images(struct image_info *kernel_info, struct image_info *user_info,
                 int max_user_images, int *num_images);

/* Setup boot VSpace. */
void init_boot_vspace(struct image_info *kernel_info);
void init_hyp_boot_vspace(struct image_info *kernel_info);

/* Assembly functions. */
extern void flush_dcache(void);
extern void cpu_idle(void);

/* Platform functions */
void platform_init(void);
void init_cpus(void);

/* Secure monitor call */
uint32_t smc(uint32_t, uint32_t, uint32_t, uint32_t);

#endif /* _ELFLOADER_H_ */

