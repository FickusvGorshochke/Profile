#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h>

#include "header/structures.h"
#include "header/functions.h"
#include "header/defines.h"


void vowels_to_next_two(Text *text) 
{
    int flag = 0;
	for (size_t i = 0; i < text->len; i++) {
		size_t needed_memory = 1 + 2 * wcslen(text->sen[i].str) * sizeof(wchar_t);
		text->sen[i].str = (wchar_t *)realloc(text->sen[i].str, needed_memory);
		for (size_t j = 0; j < wcslen(text->sen[i].str); j++) {
			if (is_vowel(text->sen[i].str[j])) {
                flag = 1;
				memmove(&text->sen[i].str[j+1], 
					   	&text->sen[i].str[j], 
					   	sizeof(wchar_t) * (wcslen(text->sen[i].str) + 1 - j));
				text->sen[i].str[j] = get_next_char(text->sen[i].str[j]);
				text->sen[i].str[j+1] = get_next_char(text->sen[i].str[j]);
				j++;
			}
		}
	}
	if (!flag) wprintf(VOWELS_ERROR);
	else wprintf(VOWELS_SUCCESS);
}


int is_vowel(wchar_t c) 
{
	return wcschr(VOWELS, towupper(c)) != NULL;
}


wchar_t get_next_char(wchar_t c) {
	if (c == L'Я') return L'А';
	if (c == L'я') return L'а';
	if (c == L'Е') return L'Ё';
	if (c == L'е') return L'ё';
	if (c == L'Ё') return L'Ж';
	if (c == L'ё') return L'ж';
	if (c == L'Z') return L'A';
	if (c == L'z') return L'a';
	return iswalpha ? c + 1 : c;
}