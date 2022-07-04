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
#include <stddef.h>
#include "morse.h"

const morse_char_t morses[] = {
		{'A', {DIT, DAH, NIL}},
		{'B', {DAH, DIT, DIT, DIT, NIL}},
		{'C', {DAH, DIT, DAH, DIT, NIL}},
		{'D', {DAH, DIT, DIT, NIL}},
		{'E', {DIT, NIL}},
		{'F', {DIT, DIT, DAH, DIT, NIL}},
		{'G', {DAH, DAH, DIT, NIL}},
		{'H', {DIT, DIT, DIT, DIT, NIL}},
		{'I', {DIT, DIT, NIL}},
		{'J', {DIT, DAH, DAH, DAH, NIL}},
		{'K', {DAH, DIT, DAH, NIL}},
		{'L', {DIT, DAH, DIT, DIT, NIL}},
		{'M', {DAH, DAH, NIL}},
		{'N', {DAH, DIT, NIL}},
		{'O', {DAH, DAH, DAH, NIL}},
		{'P', {DIT, DAH, DAH, DIT, NIL}},
		{'Q', {DAH, DAH, DIT, DAH, NIL}},
		{'R', {DIT, DAH, DIT, NIL}},
		{'S', {DIT, DIT, DIT, NIL}},
		{'T', {DAH, NIL}},
		{'U', {DIT, DIT, DAH, NIL}},
		{'V', {DIT, DIT, DIT, DAH, NIL}},
		{'W', {DIT, DAH, DAH, NIL}},
		{'X', {DAH, DIT, DIT, DAH, NIL}},
		{'Y', {DAH, DIT, DAH, DAH, NIL}},
		{'Z', {DAH, DAH, DIT, DIT, NIL}},

		{'0', {DAH, DAH, DAH, DAH, DAH, NIL}},
		{'1', {DIT, DAH, DAH, DAH, DAH, NIL}},
		{'2', {DIT, DIT, DAH, DAH, DAH, NIL}},
		{'3', {DIT, DIT, DIT, DAH, DAH, NIL}},
		{'4', {DIT, DIT, DIT, DIT, DAH, NIL}},
		{'5', {DIT, DIT, DIT, DIT, DIT, NIL}},
		{'6', {DAH, DIT, DIT, DIT, DIT, NIL}},
		{'7', {DAH, DAH, DIT, DIT, DIT, NIL}},
		{'8', {DAH, DAH, DAH, DIT, DIT, NIL}},
		{'9', {DAH, DAH, DAH, DAH, DIT, NIL}},

		// {'\0', {NIL}} // nul terminated lol
};

morse_char_t encode_morse(char ch)
{
	const size_t len = sizeof(morses) / sizeof(morses[0]);
	for (size_t i = 0; i < len; i++)
	{
		if (morses[i].orig == ch)
			return morses[i];
	}
	return (morse_char_t){'\0', {NIL}};
}

char decode_morse(uint8_t symbols[])
{
	// size_t possibles[]; // array of possible indices
	const size_t len = sizeof(morses) / sizeof(morses[0]);
	for (size_t i = 0; i < len; i++)
	{
		// Compare loop
		for (size_t j = 0; j < MAX_SYMBOLS_CHAR; j++)
		{
			if (symbols[j] != morses[i].symbols[j])
				goto OUTER;					 // 'continue outer'
			if (symbols[j] == NIL) // if both are NIL, then return match
				break;
		}
		return morses[i].orig;
	OUTER:;
	}
	return '\0';
}