#define F_CPU 14745600UL

#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>

#include "constructor.h"

int main(void){

	struct CLASS_USART test = CLASS_USART_CONSTRUCTOR();

	test.USART_INIT(MYUBRR);
	while(1){
		test.LED_TEST(1);
		_delay_ms(20);
		test.LED_TEST(0);
		test.USART_SEND_CHAR('0');
		test.USART_SEND_CHAR('1');
		test.USART_SEND_CHAR('2');

		test.USART_SEND_CHAR('a');
		test.USART_SEND_CHAR('b');
		test.USART_SEND_CHAR('c');

	}
	return 0;
}
