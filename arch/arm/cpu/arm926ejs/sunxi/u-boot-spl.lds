/*
 * (C) Copyright 2018
 * Icenowy Zheng <icenowy@aosc.io>
 *
 * Based on arch/arm/cpu/armv7/sunxi/u-boot-spl.lds:
 *
 * (C) Copyright 2012
 * Allwinner Technology Co., Ltd. <www.allwinnertech.com>
 * Tom Cubie <tangliang@allwinnertech.com>
 *
 * Based on omap-common/u-boot-spl.lds:
 *
 * (C) Copyright 2002
 * Gary Jennejohn, DENX Software Engineering, <garyj@denx.de>
 *
 * (C) Copyright 2010
 * Texas Instruments, <www.ti.com>
 *	Aneesh V <aneesh@ti.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */
MEMORY { .sram : ORIGIN = CONFIG_SPL_TEXT_BASE,\
		LENGTH = CONFIG_SPL_MAX_SIZE }
MEMORY { .sdram : ORIGIN = CONFIG_SPL_BSS_START_ADDR, \
		LENGTH = CONFIG_SPL_BSS_MAX_SIZE }

OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(_start)
SECTIONS
{
	.text      :
	{
		__start = .;
		*(.vectors)
		arch/arm/cpu/arm926ejs/start.o	(.text)
		*(.text*)
	} > .sram

	. = ALIGN(4);
	.rodata : { *(SORT_BY_ALIGNMENT(.rodata*)) } >.sram

	. = ALIGN(4);
	.data : { *(SORT_BY_ALIGNMENT(.data*)) } >.sram

	. = ALIGN(4);
	.u_boot_list : {
		KEEP(*(SORT(.u_boot_list*)));
	} > .sram

	. = ALIGN(4);
	__image_copy_end = .;
	_end = .;

	.bss :
	{
		. = ALIGN(4);
		__bss_start = .;
		*(.bss*)
		. = ALIGN(4);
		__bss_end = .;
	} > .sdram
}