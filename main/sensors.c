#include <stdio.h>
#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_timer.h>

#include "utils.h"
#include "sensors.h"
#include "serial.h"

void sensors_configure(void) {
    gpio_config_t input_conf = {
        .pin_bit_mask = (1ULL << ECHO_PIN),
        .mode = GPIO_MODE_INPUT
    };

    gpio_config_t output_conf = {
        .pin_bit_mask = (1ULL << TRIGGER_PIN) 
            | (1ULL << GREEN_PIN)
            | (1ULL << YELLOW_PIN)
            | (1ULL << RED_PIN)
            | (1ULL << SPEAKER_PIN),
        .mode = GPIO_MODE_OUTPUT
    };

    gpio_config(&input_conf);
    gpio_config(&output_conf);
    serial_write("Sensors configured\n");
}

void sensors_run(void) {
    // Reset the trigger pin
    gpio_set_level(TRIGGER_PIN, 0);
    vTaskDelay(60 / portTICK_PERIOD_MS);

    // Trigger the sensor
    gpio_set_level(TRIGGER_PIN, 1);
    vTaskDelay(1 / portTICK_PERIOD_MS);
    gpio_set_level(TRIGGER_PIN, 0);

    long duration = pulseIn(ECHO_PIN, 1);
    float distance = duration / 58.0;
    float distanceInches = distance / 2.54;

    if (distanceInches > 20) {
        gpio_set_level(GREEN_PIN, 1);
        gpio_set_level(YELLOW_PIN, 0);
        gpio_set_level(RED_PIN, 0);
        gpio_set_level(SPEAKER_PIN, 0);
    } else if (distanceInches > 10) {
        gpio_set_level(GREEN_PIN, 0);
        gpio_set_level(YELLOW_PIN, 1);
        gpio_set_level(RED_PIN, 0);
        gpio_set_level(SPEAKER_PIN, 0);
    } else {
        gpio_set_level(GREEN_PIN, 0);
        gpio_set_level(YELLOW_PIN, 0);
        gpio_set_level(RED_PIN, 1);
        gpio_set_level(SPEAKER_PIN, 1);
        vTaskDelay(6 / portTICK_PERIOD_MS);
        gpio_set_level(SPEAKER_PIN, 0);
    }
}