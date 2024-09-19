/*
    Author: Wael Hassan
    18/9/2024
 */


#include<stdio.h>
#include"stdlib.h"
#include"lifo.h"

unsigned int buffer1 [5];

void main()
{
	unsigned int i,item=0;
	LIFO_BUF uart,i2c;
	LIFO_INIT(&uart , buffer1, 5);
	unsigned int* buffer2 = (unsigned int*) malloc (5*sizeof(unsigned int));
	LIFO_INIT(&i2c , buffer2, 5);

	for(i=0;i<5;i++)
	{
		if( LIFO_ADD_ITME(&uart,i)==lifo_no_error)
		    printf("uart add :%d\n",i);
	}

	for(i=0;i<5;i++)
	{
		if( LIFO_GET_ITME(&uart,&item)== lifo_no_error)
		   printf("uart get :%d\n",item);
	}
}