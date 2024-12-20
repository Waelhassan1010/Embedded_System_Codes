/**
 ******************************************************************************
 * @file           : main.c
 * @author         : wael
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */



#include<stdio.h>
#include"Platform_Types.h"

#define RCC_BASE    0x40021000
#define PortA_BASE  0x40010800

#define RCC_APB2ENR *(vuint32*)(RCC_BASE+0X18)
#define GPIO_CHR    *(vuint32*)(PortA_BASE+0X04)
#define GPIO_ODR    *(vuint32*)(PortA_BASE+0X0C)

#define RCC_IOPAEN  (1<<2)
#define GPIOA13      (1UL<<13)

typedef union{
	vuint32 all;
	struct {
		vuint32 reserved :13;
		vuint32 p_13 :1;
	}pin;
}RO;

volatile RO * R_ODR=(volatile RO*)(PortA_BASE+0X0C);
unsigned char g_varaibles[3]={1,2,3};
unsigned char const const_varaibles[3] ={1,2,3};

int main(void)
{
	RCC_APB2ENR |=RCC_IOPAEN;
	GPIO_CHR &=0xff0fffff;
	GPIO_CHR |=0x00200000;
	while(1)
	{
		R_ODR ->pin.p_13=1;
		for(int i=0;i<500;i++);
		R_ODR ->pin.p_13=0;
		for(int i=0;i<500;i++);
	}
}
