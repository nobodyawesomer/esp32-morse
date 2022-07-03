/**
 * @file blink.c
 * @author Nobody (nobodyawesomer@proton.me)
 * @brief Blinking Morse
 * @version 0.1
 * @date 2022-06-24
 *
 * @copyright Copyright (c) 2022
 *
 */
// #include <stdio.h>
// #include <stddef.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
// #include "driver/gpio.h"
#include "esp_log.h"
#include "led_strip.h"
#include "morse.h"
#include "blink.h"

static const char *TAG = "Blinker";

void led_strip_on(led_strip_t *strip)
{
	strip->set_pixel(strip, 0, 16, 16, 16);
	strip->refresh(strip, 100);
}

void led_strip_off(led_strip_t *strip)
{
	strip->clear(strip, 50);
}

void wait_units(uint8_t units)
{
	vTaskDelay(units * CONFIG_MORSE_UNIT_MS / portTICK_PERIOD_MS);
}

void blink_char(led_strip_t *strip, morse_char_t mchar)
{
	uint8_t *syms = mchar.symbols;
	ESP_LOGI(TAG, "Sending '%c'", mchar.orig);
	for (size_t i = 0; i < 5; i++)
	{
		if (syms[i] == NIL)
			break;
		led_strip_on(strip);
		wait_units(syms[i]); // DIT->1, DAH->3
		led_strip_off(strip);
		wait_units(SYMBOL_SPACE); // TODO: cut last symbol somehow. Want it interspersed without trailing OFF.
	}
}

void blink_str(led_strip_t *strip, char *str)
{
	for (uint i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
		{
			ESP_LOGI(TAG, "SPACE");
			wait_units(WORD_SPACE);
		}
		else
		{
			blink_char(strip, encode_morse(str[i]));
			wait_units(CHAR_SPACE); // TODO: cut trailing space after word end
		}
	}
}