#include"uart.h"
unsigned char string_buffer[100]="wael";
void main (void )
{
UART_SEND_STRING(string_buffer);
}