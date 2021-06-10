/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * suniv DRAM controller register definition
 *
 * Copyright (C) 2021 Iscle <albertiscle9@gmail.com>
 *
 * Copyright (C) 2018 Icenowy Zheng <icenowy@aosc.io>
 *
 * Based on xboot's arch/arm32/mach-f1c100s/sys-dram.c, which is:
 *
 * Copyright (C) 2007-2018 Jianjun Jiang <8192542@qq.com>
 */

#ifndef _SUNXI_DRAM_SUNIV_H
#define _SUNXI_DRAM_SUNIV_H

//#define PIO_SDRAM_DRV			(0x2c0)
//#define PIO_SDRAM_PULL			(0x2c4)

struct sunxi_dram_reg {
	u32 sconr;		/* 0x00 */
	u32 stmg0r;		/* 0x04 */
	u32 stmg1r;		/* 0x08 */
	u32 sctlr;		/* 0x0c */
	u32 srefr;		/* 0x10 */
	u32 sextmr;		/* 0x14 */
	u8 reserved1[12];
	u32 ddlyr;		/* 0x24 */
	u32 dadrr;		/* 0x28 */
	u32 dvalr;		/* 0x2c */
	u32 drptr0;		/* 0x30 */
	u32 drptr1;		/* 0x34 */
	u32 drptr2;		/* 0x38 */
	u32 drptr3;		/* 0x3c */
	u32 sefr;		/* 0x40 */
	u32 mae;		/* 0x44 */
	u32 aspr;		/* 0x48 */
	u32 sdly0;		/* 0x4c */
	u32 sdly1;		/* 0x50 */
	u32 sdly2;		/* 0x54 */
	u8 reserved2[168];
	u32 mcr0;		/* 0x100 */
	u32 mcr1;		/* 0x104 */
	u32 mcr2;		/* 0x108 */
	u32 mcr3;		/* 0x10c */
	u32 mcr4;		/* 0x110 */
	u32 mcr5;		/* 0x114 */
	u32 mcr6;		/* 0x118 */
	u32 mcr7;		/* 0x11c */
	u32 mcr8;		/* 0x120 */
	u32 mcr9;		/* 0x124 */
	u32 mcr10;		/* 0x128 */
	u32 mcr11;		/* 0x12c */
	u8 reserved3[16];
	u32 bwcr;		/* 0x140 */
};

#endif /* _SUNXI_DRAM_SUNIV_H */
