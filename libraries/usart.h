struct CLASS_USART{
	void (*USART_INIT) (unsigned int);
	void (*USART_SEND_CHAR) (unsigned char);
	void (*USART_SEND_STRING) (char*);
	void (*LED_TEST) (unsigned char);
};

/*INIT FUNCTIONS*/
void USART_INIT( unsigned int ubrr){
    /*activate TX port*/
    DDRD|=1<<PD1;
    /* Set baud rate */
    UBRRH = (unsigned char)(ubrr>>8);
    UBRRL = (unsigned char)ubrr;
    /* Set frame format: 8data, 1stop bit */
    UCSRC = (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
    /* Enable receiver and transmitter */
    UCSRB = (1<<RXEN)|(1<<TXEN);
}

static void USART_SEND_CHAR( unsigned char data ){
    /* Wait for empty transmit buffer */
    while ( !( UCSRA & (1<<UDRE)) );
    /* Put data into buffer, sends the data */
    UDR = data;
}

void USART_SEND_STRING( char data[10]){
    unsigned char i=0;
    while(data[i]!='\0'){
        USART_SEND_CHAR(data[i]);
        i++;
    }
}

void LED_TEST(unsigned char i){
	DDRB=0xFF;
	if(i){
		PORTB|=0x01;
	}
	else{
		PORTB&=~(0x01);
	}
}

/*
void USART_TRANSMIT_STRING(char data*){
	unsigned char i=0;
	while(data[i]!='\0'){
		USART_TRANSMIT(data[i]);
		i++;
	}
*/
