/**
 * @file input.h
 * @author Nobody (nobodyawesomer@proton.me)
 * @brief Morse input from GPIO
 * @version 0.1
 * @date 2022-07-02
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef __INPUT_H
#define __INPUT_H
#include <stdint.h>

/**
 * @brief Processes an input of a certain length (logical high)
 * Should be triggered by some current input going logically low.
 *
 * @param length_millis the length of the input in milliseconds
 */
void process_input(uint32_t length_millis);

/**
 * @brief Process a space (lack of input) corresponding to a
 * break between words.
 */
void process_space();

/**
 * @brief Process a NIL (character termination symbol),
 * which sends a character determined by the inputs/symbols (DIT, DAH)
 * sent before the last NIL.
 * Multiple NILs in sequence are a noop.
 *
 */
void process_nil();

#endif /* __INPUT_H */