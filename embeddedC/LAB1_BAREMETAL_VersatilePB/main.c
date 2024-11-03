#include"uart.h"

char arr[100]="wael";

void main(void)
{
	uart_send_string(arr);
}