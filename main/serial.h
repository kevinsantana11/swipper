#include <driver/uart.h>
#include <driver/gpio.h>
#include "config.h"

#define UART_PORT_NUM      CONF_UART_PORT_NUM
#define UART_TX_PIN        CONF_UART_TX_PIN
#define UART_RX_PIN        CONF_UART_RX_PIN
#define UART_BAUD_RATE     CONF_UART_BAUD_RATE
#define UART_BUF_SIZE      1024

void serial_configure(void);

void serial_write(char* message);

void _serial_write(char* message, int max_length);