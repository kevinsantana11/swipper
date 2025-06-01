#include <driver/gpio.h>
#include <driver/uart.h>
#include <esp_wifi.h>

#define CONF_UART_PORT_NUM      UART_NUM_0
#define CONF_UART_TX_PIN        GPIO_NUM_1
#define CONF_UART_RX_PIN        GPIO_NUM_3
#define CONF_UART_BAUD_RATE     9600

#define CONF_TRIGGER_PIN GPIO_NUM_13
#define CONF_ECHO_PIN GPIO_NUM_12
#define CONF_GREEN_PIN GPIO_NUM_14
#define CONF_YELLOW_PIN GPIO_NUM_27
#define CONF_RED_PIN GPIO_NUM_26
#define CONF_SPEAKER_PIN GPIO_NUM_25

#ifdef SECRETS
#include "secrets.h"
#define CONF_ESP_WIFI_SSID SECRETS_WIFI_SSID
#define CONF_ESP_WIFI_PASS SECRETS_WIFI_PASS    
#else
#define CONF_ESP_WIFI_SSID "wifi-ssid"
#define CONF_ESP_WIFI_PASS "wifi-pass"
#endif
#define CONF_ESP_MAXIMUM_RETRY  3