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
 *
 * @param length_millis the length of the input in milliseconds
 */
void process_input(uint32_t length_millis);

/**
 * @brief Process a space (lack of input) of a length (logical low), between inputs
 * Should be triggered by some current input going logically high.
 *
 * @param length_millis the length since the last input
 */
void process_space(uint32_t length_millis);

#endif /* __INPUT_H */