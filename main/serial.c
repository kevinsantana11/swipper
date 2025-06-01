#include <driver/uart.h>
#include <driver/gpio.h>

#include "serial.h"

void serial_configure(void) {
    const uart_config_t uart_config = {
        .baud_rate = UART_BAUD_RATE,
        .data_bits = UART_DATA_8_BITS,
        .parity    = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
    };

    // Configure UART
    uart_param_config(UART_PORT_NUM, &uart_config);
    uart_set_pin(UART_PORT_NUM, UART_TX_PIN, UART_RX_PIN, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);

    // Install UART driver
    uart_driver_install(UART_PORT_NUM, UART_BUF_SIZE * 2, 0, 0, NULL, 0);
    serial_write("Serial port configured\n");
}

void serial_write(char* message) {
    _serial_write(message, 512);
}

void _serial_write(char* message, int max_length) {
    uint32_t length = 0;
    char currChar = *message;
    while (currChar != '\0' && length < max_length) {
        length += 1;
        currChar = *(message + length);
    }
    uart_write_bytes(UART_PORT_NUM, &message, length);
}