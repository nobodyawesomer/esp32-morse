#include <stdio.h>
#include <math.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "led_strip.h"
#include "sdkconfig.h"
#include "morse.h"
#include "blink.h"

static const char *TAG = "Morse";

/// I don't actually care to fix this at this point. Later.
static uint32_t naive_tick_timer = 0;

static led_strip_t *pStrip_a;

const uint32_t COLOR_CAP = 24;

static void idle_led(void)
{
    float led_brightness = (cos(naive_tick_timer * 3.141592 / 32) + 1) / 2;
    // ESP_LOGD(TAG, "Light level at %d from %.4f", (uint32_t)(led_brightness * COLOR_CAP), led_brightness);
    /* Set the LED pixel using RGB from 0 (0%) to 255 (100%) for each color */
    pStrip_a->set_pixel(pStrip_a, 0, led_brightness * COLOR_CAP, led_brightness * COLOR_CAP, led_brightness * COLOR_CAP);
    /* Refresh the strip to send data */
    pStrip_a->refresh(pStrip_a, 100);
}

static void configure_led(void)
{
    ESP_LOGI(TAG, "Configured to blink addressable LED!");
    /* LED strip initialization with the GPIO and pixels number*/
    pStrip_a = led_strip_init(CONFIG_BLINK_LED_RMT_CHANNEL, CONFIG_BLINK_GPIO, 1);
    /* Set all LED off to clear all pixels */
    pStrip_a->clear(pStrip_a, 50);
}

void app_main(void)
{

    /* Configure the peripheral according to the LED type */
    configure_led();
    // blink_char(pStrip_a, encode_morse('A'));
    blink_str(pStrip_a, "CQ CQ MA NAME JEFF R");

    ESP_LOGI(TAG, "Idling the LED!");
    while (1)
    {
        idle_led();
        naive_tick_timer++;
        vTaskDelay(50 / portTICK_PERIOD_MS); // TODO: configify
    }
}
