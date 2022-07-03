/**
 * @file morse.h
 * @author Nobody (nobodyawesomer@proton.me)
 * @brief Morse Code definitions
 * @version 0.1
 * @date 2022-06-24
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef __MORSE_H
#define __MORSE_H
#include <stddef.h>
#include <stdint.h>

#define MAX_SYMBOLS_CHAR ((size_t)8) ///< Maximum symbols that can represent a character in Morse

// TODO: configify this
#define SYMBOL_SPACE 1 ///< The gap between two symbols (dit/dah)
#define CHAR_SPACE 3	 ///< The gap between two characters within a word
#define WORD_SPACE 7	 ///< The gap between two words

#define DIT ((uint8_t)1) ///< Morse "dit"/dot
#define DAH ((uint8_t)3) ///< Morse "dah"/dash
#define NIL ((uint8_t)0) ///< Morse "nothing"

/**
 * @brief Represents a character in morse.
 * For example, 'A' is '.-' (DIT DAH)
 *
 */
typedef struct morse_char_s
{
	char orig;
	uint8_t symbols[MAX_SYMBOLS_CHAR];
} morse_char_t;

/**
 * @brief Get the morse representation of a character
 *
 * @param ch the character to convert
 * @return morse_char_t
 */
morse_char_t encode_morse(char ch);

#endif /* __MORSE_H */