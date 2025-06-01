#include <stdio.h>
#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_timer.h>

#include "utils.h"

long pulseIn(gpio_num_t pin, int level) {
    // Wait till level isn't set
    while (gpio_get_level(pin) == level);

    // Lets wait till we catch an edge
    while(gpio_get_level(pin) != level);

    uint64_t pulseStart = esp_timer_get_time();

    while(gpio_get_level(pin) == level);

    uint64_t pulseEnd = esp_timer_get_time();
    return (long) (pulseEnd - pulseStart);
}