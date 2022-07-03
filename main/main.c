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
#include "input.h"

static const char *TAG = "Morse";

/// I don't actually care to fix this at this point. Later.
static uint32_t naive_tick_timer = 0;

static led_strip_t *pStrip_a;

const uint32_t COLOR_CAP = 24;

static void idle_led(void)
{
    const float PI = 3.14159265358979323846264;
    float theta = 2 * PI * naive_tick_timer / 64; // 'sample rate' 64 per period. 360 would mean naive_tick_timer is degrees.
#ifdef CONFIG_IDLE_ANIM_RAINBOW
    float red = (cos(theta) + 1) / 2;
    float green = (cos(theta + 2 * PI / 3) + 1) / 2;
    float blue = (cos(theta + 4 * PI / 3) + 1) / 2;
    pStrip_a->set_pixel(pStrip_a, 0, red * COLOR_CAP, green * COLOR_CAP, blue * COLOR_CAP);
#else // CONFIG_IDLE_ANIM_BREATHE as default
    float led_brightness = (cos(theta) + 1) / 2;
    pStrip_a->set_pixel(pStrip_a, 0, led_brightness * COLOR_CAP, led_brightness * COLOR_CAP, led_brightness * COLOR_CAP);
    // ESP_LOGD(TAG, "Light level at %d from %.4f", (uint32_t)(led_brightness * COLOR_CAP), led_brightness);
#endif
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

static void configure_gpio(void)
{
    const gpio_num_t pin = CONFIG_INPUT_GPIO;
    ESP_LOGI(TAG, "Configured to take input from pin %d", pin);
    gpio_reset_pin(pin);
    gpio_set_direction(pin, GPIO_MODE_INPUT);
    // gpio_set_pull_mode(pin, GPIO_PULLUP_ONLY); // default on reset
}

void app_main(void)
{

    /* INIT */
    configure_led();
    configure_gpio();
    uint32_t duration_on = 0;
    uint32_t duration_off = 0;
    /* TINI */

    // blink_char(pStrip_a, encode_morse('A'));
    blink_str(pStrip_a, "CQ CQ MA NAME JEFF R");

    ESP_LOGI(TAG, "Idling the LED!");
    while (1)
    {
        idle_led();
        naive_tick_timer++;
        // TODO: consider interrupt-driven or smthn rather than this polling
        if (gpio_get_level(CONFIG_INPUT_GPIO))
        { // physical HIGH means space (off)
            duration_off += CONFIG_REFRESH_MS;
            if (duration_on > 0) // only happen once, when switch happens
            {
                process_input(duration_on);
                duration_on = 0;
            }
        }
        else
        { // physical LOW means active input (on)
            duration_on += CONFIG_REFRESH_MS;
            if (duration_off > 0) // only happen once, when switch happens
            {
                process_space(duration_off);
                duration_off = 0;
            }
            // ESP_LOGD(TAG, "Input high!");
        }
        vTaskDelay(CONFIG_REFRESH_MS / portTICK_PERIOD_MS);
    }
}
