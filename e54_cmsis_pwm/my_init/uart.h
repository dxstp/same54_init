/*
 * uart.h
 *
 * Created: 11.12.2018 11:28:03
 *  Author: M19931
 */ 


#ifndef UART_H_
#define UART_H_

void init_uart(void);
void mput(char c);

int32_t stdio_io_read(uint8_t *const buf, const uint16_t length);
int32_t stdio_io_write(const uint8_t *const buf, const uint16_t length);


#endif /* UART_H_ */