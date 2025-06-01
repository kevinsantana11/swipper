#include <nvs_flash.h>

#include "sensors.h"
#include "wifi.h"
#include "serial.h"

void app_main(void)
{
    //Initialize NVS
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
      ESP_ERROR_CHECK(nvs_flash_erase());
      ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);
    serial_configure(); // configure serial uart0 (over usb)
    wifi_init_sta(); // init wifi
    sensors_configure(); // init sensors (input/output)

    serial_write("System configured!\n");
    while (1) {
        sensors_run();
    }
}