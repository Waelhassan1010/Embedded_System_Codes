#include<stdio.h>
#include<Platform_Types.h>
#define SYSCTL_RCC2_R     (*(volatile unsigned long*)0x400FE108)
#define GPIO_PORTF_DARA_R (*(volatile unsigned long*)0x400253fc)
#define GPIO_PORTF_DIR_R  (*(volatile unsigned long*)0x40025400)
#define GPIO_PORTF_DEN_R  (*(volatile unsigned long*)0x4002551c)

void main()
{
	volatile int delay;
	SYSCTL_RCC2_R=0x20;
	for(delay=0;delay<200;delay++);
	GPIO_PORTF_DEN_R |=1<<3;
	GPIO_PORTF_DIR_R |=1<<3;
	while(1)
	{
		GPIO_PORTF_DARA_R |=1<<3;
		for(delay=0;delay<20000;delay++);
	    GPIO_PORTF_DARA_R &=~(1<<3);
	    for(delay=0;delay<20000;delay++);
		   
	}
	
}