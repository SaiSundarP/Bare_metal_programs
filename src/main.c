#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
// Linker stubs for SDK compatibility
#include <stdint.h>
#include <stdbool.h>

// ESP8266 SDK headers for GPIO
#include "esp_common.h"
#include "gpio.h"

uint32_t user_rf_cal_sector_set(void)
{
    // Return 0 to use default calibration sector (works for most flash layouts)
    return 0;
}

/*
 * LED Blink Task
 * NodeMCU onboard LED is connected to GPIO2
 * Active LOW:
 *   GPIO LOW  -> LED ON
 *   GPIO HIGH -> LED OFF
 */
void blink_led_task(void *pvParameters)
{
    bool led_state = false;

    while (1)
    {
        led_state = !led_state;

        if (led_state)
        {
            GPIO_OUTPUT_SET(2, 0); // LED ON
            printf("LED ON\n");
        }
        else
        {
            GPIO_OUTPUT_SET(2, 1); // LED OFF
            printf("LED OFF\n");
        }

        vTaskDelay(500); // Tick-based delay (adjust if needed for ms->ticks conversion)
    }
}

void user_init(void)
{
    printf("\n");
    printf("================================\n");
    printf(" ESP8266 RTOS SDK LED Blink\n");
    printf("================================\n");

    /* Configure GPIO2 as output */
    PIN_FUNC_SELECT(PERIPHS_IO_MUX_GPIO2_U, FUNC_GPIO2);
    GPIO_AS_OUTPUT(GPIO_Pin_2);

    /* LED OFF initially */
    GPIO_OUTPUT_SET(2, 1);

    /* Create blink task */
    if (xTaskCreate(
            blink_led_task,"BlinkTask",2048,NULL,5,NULL) != pdPASS)
    {
        printf("Failed to create Blink Task!\n");
    }
}

