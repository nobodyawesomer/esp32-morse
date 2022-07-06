/**
 * @file blink.h
 * @author Nobody (nobodyawesomer@proton.me)
 * @brief Blinking Morse
 * @version 0.1
 * @date 2022-06-24
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef __BLINK_H
#define __BLINK_H

#include "led_strip.h"
#include "morse.h"

/**
 * @brief Blinks a morse character out to the given LED strip.
 * The strip must be initialized properly.
 *
 * @param strip
 * @param mchar
 */
void blink_char(led_strip_t *strip, morse_char_t mchar);

/**
 * @brief Blinks a word in morse out to the given LED strip.
 * The strip must be initialized properly.
 *
 * @param strip
 * @param str
 */
void blink_str(led_strip_t *strip, char *str);

#endif /* __BLINK_H */