#include"uart.h"

#define UART0DR  *((volatile uint32*)((uint32 *)0x101f1000))

void UART_SEND_STRING(unsigned char* P_tx_string)
{
    while(*P_tx_string!='\0')
    {
        UART0DR=(uint32 )(*P_tx_string);
        P_tx_string++;

    }

}