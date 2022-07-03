/**
 * @file input.c
 * @author Nobody (nobodyawesomer@proton.me)
 * @brief Morse input from GPIO
 * @version 0.1
 * @date 2022-07-02
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stddef.h>
#include <stdint.h>
#include "esp_log.h"
#include "sdkconfig.h"
#include "morse.h"
#include "input.h"

static const char *TAG = "Input";

static uint8_t symbol_stack[MAX_SYMBOLS_CHAR];
static size_t current;

/// Pushes a DIT to the symbol stack
static void push_dit()
{
	ESP_LOGI(TAG, "Recieved DIT");
}

/// Pushes a DAH to the symbol stack
static void push_dah()
{
	ESP_LOGI(TAG, "Recieved DAH");
}

/// Pushes a NIL (character termination symbol) to the symbol stack, then processes the entire stack and resets it.
static void push_nil()
{
	ESP_LOGI(TAG, "Recieved NIL; processing character");
	// Compare chars to morse chars somehow

	// Send output to ESP_LOG or printf
}

void process_input(uint32_t length_millis)
{
	ESP_LOGD(TAG, "Recieved input of %d ms", length_millis);
	if (length_millis > (uint32_t)(CONFIG_MORSE_UNIT_MS * DAH))
		push_dah();
	else if (length_millis > (uint32_t)(CONFIG_MORSE_UNIT_MS * DIT))
		push_dit();
}

void process_space(uint32_t length_millis)
{
	ESP_LOGD(TAG, "Recieved space of %d ms", length_millis);
	// TODO: if length > wordlength, push space
	if (length_millis > (uint32_t)(CONFIG_MORSE_UNIT_MS * CHAR_SPACE)) // length > length-between-chars implies NIL
		push_nil();
}