/****************************************************************************
 * @file     clock.h
 * @version  V1.05
 * @Date     2021/02/20-17:27:09 
 * @brief    NuMicro generated code file
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (C) 2013-2021 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/

#ifndef __CLOCK_H__
#define __CLOCK_H__

#ifdef __cplusplus
extern "C"
{
#endif
void clock_init_fmcidle(void);
void clock_deinit_fmcidle(void);
void clock_init_gpioa(void);
void clock_deinit_gpioa(void);
void clock_init_gpiob(void);
void clock_deinit_gpiob(void);
void clock_init_gpioc(void);
void clock_deinit_gpioc(void);
void clock_init_gpiod(void);
void clock_deinit_gpiod(void);
void clock_init_gpioe(void);
void clock_deinit_gpioe(void);
void clock_init_gpiof(void);
void clock_deinit_gpiof(void);
void clock_init_isp(void);
void clock_deinit_isp(void);
void clock_init_wdt(void);
void clock_deinit_wdt(void);
void clock_init_wwdt(void);
void clock_deinit_wwdt(void);
void clock_init_base(void);
void clock_init(void);
#ifdef __cplusplus
}
#endif
#endif /*__CLOCK_H__*/

/*** (C) COPYRIGHT 2013-2021 Nuvoton Technology Corp. ***/
