/****************************************************************************
 * @file     clock.c
 * @version  V1.05
 * @Date     2021/02/20-17:27:09 
 * @brief    NuMicro generated code file
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (C) 2013-2021 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/

/********************
MCU:NUC029KGE(LQFP128)
Base Clocks:
LIRC:10kHz
HIRC:22.1184MHz
HIRC48:48MHz
LXT:32.7680kHz
HXT:12MHz
PLL:72MHz
HCLK:72MHz
PCLK0:72MHz
PCLK1:72MHz
Enabled-Module Frequencies:
FMCIDLE=Bus Clock(HCLK):72MHz/Engine Clock:22.1184MHz
GPIOA=Bus Clock(HCLK):72MHz
GPIOB=Bus Clock(HCLK):72MHz
GPIOC=Bus Clock(HCLK):72MHz
GPIOD=Bus Clock(HCLK):72MHz
GPIOE=Bus Clock(HCLK):72MHz
GPIOF=Bus Clock(HCLK):72MHz
ISP=Bus Clock(HCLK):72MHz/Engine Clock:22.1184MHz
WDT=Bus Clock(PCLK0):72MHz/Engine Clock:10kHz
WWDT=Bus Clock(PCLK0):72MHz/Engine Clock:35.1563kHz
********************/

#include "NUC029xGE.h"

void clock_init_fmcidle(void)
{
    CLK_EnableModuleClock(FMCIDLE_MODULE);

    return;
}

void clock_deinit_fmcidle(void)
{
    CLK_DisableModuleClock(FMCIDLE_MODULE);

    return;
}

void clock_init_gpioa(void)
{
    CLK_EnableModuleClock(GPIOA_MODULE);

    return;
}

void clock_deinit_gpioa(void)
{
    CLK_DisableModuleClock(GPIOA_MODULE);

    return;
}

void clock_init_gpiob(void)
{
    CLK_EnableModuleClock(GPIOB_MODULE);

    return;
}

void clock_deinit_gpiob(void)
{
    CLK_DisableModuleClock(GPIOB_MODULE);

    return;
}

void clock_init_gpioc(void)
{
    CLK_EnableModuleClock(GPIOC_MODULE);

    return;
}

void clock_deinit_gpioc(void)
{
    CLK_DisableModuleClock(GPIOC_MODULE);

    return;
}

void clock_init_gpiod(void)
{
    CLK_EnableModuleClock(GPIOD_MODULE);

    return;
}

void clock_deinit_gpiod(void)
{
    CLK_DisableModuleClock(GPIOD_MODULE);

    return;
}

void clock_init_gpioe(void)
{
    CLK_EnableModuleClock(GPIOE_MODULE);

    return;
}

void clock_deinit_gpioe(void)
{
    CLK_DisableModuleClock(GPIOE_MODULE);

    return;
}

void clock_init_gpiof(void)
{
    CLK_EnableModuleClock(GPIOF_MODULE);

    return;
}

void clock_deinit_gpiof(void)
{
    CLK_DisableModuleClock(GPIOF_MODULE);

    return;
}

void clock_init_isp(void)
{
    CLK_EnableModuleClock(ISP_MODULE);

    return;
}

void clock_deinit_isp(void)
{
    CLK_DisableModuleClock(ISP_MODULE);

    return;
}

void clock_init_wdt(void)
{
    CLK_EnableModuleClock(WDT_MODULE);
    CLK_SetModuleClock(WDT_MODULE, CLK_CLKSEL1_WDTSEL_LIRC, MODULE_NoMsk);

    return;
}

void clock_deinit_wdt(void)
{
    CLK_DisableModuleClock(WDT_MODULE);

    return;
}

void clock_init_wwdt(void)
{
    CLK_EnableModuleClock(WWDT_MODULE);
    CLK_SetModuleClock(WWDT_MODULE, CLK_CLKSEL2_WWDTSEL_HCLK_DIV2048, MODULE_NoMsk);

    return;
}

void clock_deinit_wwdt(void)
{
    CLK_DisableModuleClock(WWDT_MODULE);

    return;
}

void clock_init_base(void)
{
    /* Enable clock source */
    CLK_EnableXtalRC(CLK_PWRCTL_LIRCEN_Msk|CLK_PWRCTL_HIRCEN_Msk|CLK_PWRCTL_LXTEN_Msk|CLK_PWRCTL_HXTEN_Msk|CLK_PWRCTL_HIRC48EN_Msk);

    /* Waiting for clock source ready */
    CLK_WaitClockReady(CLK_STATUS_LIRCSTB_Msk|CLK_STATUS_HIRCSTB_Msk|CLK_STATUS_LXTSTB_Msk|CLK_STATUS_HXTSTB_Msk|CLK_STATUS_HIRC48STB_Msk);

    /* Disable PLL first to avoid unstable when setting PLL */
    CLK_DisablePLL();

    /* Set PLL frequency */
    CLK->PLLCTL = (CLK->PLLCTL & ~(0x000FFFFFUL)) | 0x00804016UL;

    /* Waiting for PLL ready */
    CLK_WaitClockReady(CLK_STATUS_PLLSTB_Msk);

    /* If the defines do not exist in your project, please refer to the related clk.h in the Header folder appended to the tool package. */
    /* Set HCLK clock */
    CLK_SetHCLK(CLK_CLKSEL0_HCLKSEL_PLL, CLK_CLKDIV0_HCLK(1));

    /* Set PCLK-related clock */
    CLK->CLKSEL0 = CLK->CLKSEL0 & ~CLK_CLKSEL0_PCLK0SEL_Msk;
    CLK->CLKSEL0 = CLK->CLKSEL0 & ~CLK_CLKSEL0_PCLK1SEL_Msk;

    return;
}

void clock_init(void)
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init System Clock                                                                                       */
    /*---------------------------------------------------------------------------------------------------------*/
    //CLK->PWRCTL = (CLK->PWRCTL & ~(0x0000200FUL)) | 0x00003C1FUL;
    //CLK->PLLCTL = (CLK->PLLCTL & ~(0x000FFFFFUL)) | 0x00804016UL;
    //CLK->CLKDIV0 = (CLK->CLKDIV0 & ~(0x00FF0FFFUL)) | 0x00000000UL;
    //CLK->CLKDIV1 = (CLK->CLKDIV1 & ~(0x0000FFFFUL)) | 0x00000000UL;
    //CLK->CLKSEL0 = (CLK->CLKSEL0 & ~(0x000000FFUL)) | 0x0000003AUL;
    //CLK->CLKSEL1 = (CLK->CLKSEL1 & ~(0x3377770FUL)) | 0x3377770FUL;
    //CLK->CLKSEL2 = (CLK->CLKSEL2 & ~(0x0F07001CUL)) | 0x00020008UL;
    //CLK->CLKSEL3 = (CLK->CLKSEL3 & ~(0x0000010FUL)) | 0x00000000UL;
    //CLK->AHBCLK = (CLK->AHBCLK & ~(0x003F809EUL)) | 0x003F8004UL;
    //CLK->APBCLK0 = (CLK->APBCLK0 & ~(0x5837337FUL)) | 0x00000001UL;
    //CLK->APBCLK1 = (CLK->APBCLK1 & ~(0x00000703UL)) | 0x00000000UL;
    //CLK->CLKOCTL = (CLK->CLKOCTL & ~(0x0000007FUL)) | 0x00000000UL;
    //SysTick->CTRL = (SysTick->CTRL & ~(0x00000005UL)) | 0x00000000UL;

    /* Unlock protected registers */
    SYS_UnlockReg();

    /* Enable base clock */
    clock_init_base();

    /* Enable module clock and set clock source */
    clock_init_fmcidle();
    clock_init_gpioa();
    clock_init_gpiob();
    clock_init_gpioc();
    clock_init_gpiod();
    clock_init_gpioe();
    clock_init_gpiof();
    clock_init_isp();
    clock_init_wdt();
    clock_init_wwdt();

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate SystemCoreClock. */
    SystemCoreClockUpdate();

    /* Lock protected registers */
    SYS_LockReg();

    return;
}

/*** (C) COPYRIGHT 2013-2021 Nuvoton Technology Corp. ***/
