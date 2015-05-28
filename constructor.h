#include "libraries/usart.h"

struct CLASS_USART CLASS_USART_CONSTRUCTOR(){
    struct CLASS_USART tempStruct;
    tempStruct.USART_INIT = USART_INIT;
    tempStruct.USART_SEND_CHAR = USART_SEND_CHAR;
    tempStruct.USART_SEND_STRING = USART_SEND_STRING;
	tempStruct.LED_TEST = LED_TEST;
    return tempStruct;
}

