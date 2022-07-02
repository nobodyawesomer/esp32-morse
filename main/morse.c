/**
 * @file morse.c
 * @author Nobody (nobodyawesomer@proton.me)
 * @brief Morse Code definitions
 * @version 0.1
 * @date 2022-06-24
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "morse.h"

morse_char_t encode_morse(char ch)
{
	switch (ch)
	{
	case 'A':
		return (morse_char_t){.orig = ch, .symbols = {DIT, DAH, NIL}};
	case 'B':
		return (morse_char_t){.orig = ch, .symbols = {DAH, DIT, DIT, DIT, NIL}};
	case 'C':
		return (morse_char_t){.orig = ch, .symbols = {DAH, DIT, DAH, DIT, NIL}};
	case 'D':
		return (morse_char_t){.orig = ch, .symbols = {DAH, DIT, DIT, NIL}};
	case 'E':
		return (morse_char_t){.orig = ch, .symbols = {DIT, NIL}};
	case 'F':
		return (morse_char_t){.orig = ch, .symbols = {DIT, DIT, DAH, DIT, NIL}};
	case 'G':
		return (morse_char_t){.orig = ch, .symbols = {DAH, DAH, DIT, NIL}};
	case 'H':
		return (morse_char_t){.orig = ch, .symbols = {DIT, DIT, DIT, DIT, NIL}};
	case 'I':
		return (morse_char_t){.orig = ch, .symbols = {DIT, DIT, NIL}};
	case 'J':
		return (morse_char_t){.orig = ch, .symbols = {DIT, DAH, DAH, DAH, NIL}};
	case 'K':
		return (morse_char_t){.orig = ch, .symbols = {DIT, DAH, DIT, NIL}};
	case 'L':
		return (morse_char_t){.orig = ch, .symbols = {DIT, DAH, DIT, DIT, NIL}};
	case 'M':
		return (morse_char_t){.orig = ch, .symbols = {DAH, DAH, NIL}};
	case 'N':
		return (morse_char_t){.orig = ch, .symbols = {DAH, DIT, NIL}};
	case 'O':
		return (morse_char_t){.orig = ch, .symbols = {DAH, DAH, DAH, NIL}};
	case 'P':
		return (morse_char_t){.orig = ch, .symbols = {DIT, DAH, DAH, DIT, NIL}};
	case 'Q':
		return (morse_char_t){.orig = ch, .symbols = {DAH, DAH, DIT, DAH, NIL}};
	case 'R':
		return (morse_char_t){.orig = ch, .symbols = {DIT, DAH, DIT, NIL}};
	case 'S':
		return (morse_char_t){.orig = ch, .symbols = {DIT, DIT, DIT, NIL}};
	case 'T':
		return (morse_char_t){.orig = ch, .symbols = {DAH, NIL}};
	case 'U':
		return (morse_char_t){.orig = ch, .symbols = {DIT, DIT, DAH, NIL}};
	case 'V':
		return (morse_char_t){.orig = ch, .symbols = {DIT, DIT, DIT, DAH, NIL}};
	case 'W':
		return (morse_char_t){.orig = ch, .symbols = {DIT, DAH, DAH, NIL}};
	case 'X':
		return (morse_char_t){.orig = ch, .symbols = {DAH, DIT, DIT, DAH, NIL}};
	case 'Y':
		return (morse_char_t){.orig = ch, .symbols = {DAH, DIT, DAH, DAH, NIL}};
	case 'Z':
		return (morse_char_t){.orig = ch, .symbols = {DAH, DAH, DIT, DIT, NIL}};

	case '0':
		return (morse_char_t){.orig = ch, .symbols = {DAH, DAH, DAH, DAH, DAH, NIL}};
	case '1':
		return (morse_char_t){.orig = ch, .symbols = {DIT, DAH, DAH, DAH, DAH, NIL}};
	case '2':
		return (morse_char_t){.orig = ch, .symbols = {DIT, DIT, DAH, DAH, DAH, NIL}};
	case '3':
		return (morse_char_t){.orig = ch, .symbols = {DIT, DIT, DIT, DAH, DAH, NIL}};
	case '4':
		return (morse_char_t){.orig = ch, .symbols = {DIT, DIT, DIT, DIT, DAH, NIL}};
	case '5':
		return (morse_char_t){.orig = ch, .symbols = {DIT, DIT, DIT, DIT, DIT, NIL}};
	case '6':
		return (morse_char_t){.orig = ch, .symbols = {DAH, DIT, DIT, DIT, DIT, NIL}};
	case '7':
		return (morse_char_t){.orig = ch, .symbols = {DAH, DAH, DIT, DIT, DIT, NIL}};
	case '8':
		return (morse_char_t){.orig = ch, .symbols = {DAH, DAH, DAH, DIT, DIT, NIL}};
	case '9':
		return (morse_char_t){.orig = ch, .symbols = {DAH, DAH, DAH, DAH, DIT, NIL}};

	default:
		return (morse_char_t){.orig = '\0', .symbols = {NIL}};
	}
}