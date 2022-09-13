#include <stdio.h>
#include <stdlib.h>
#include <wctype.h>
#include <wchar.h>

#include "header/structures.h"
#include "header/functions.h"
#include "header/defines.h"

Text text_input() 
{
	Text text = {NULL, 0};
	size_t sen_size = 1;
	size_t str_size = INIT_STR_SIZE;
	size_t i = 0, j = 0;
	wchar_t c;

	text.sen = (Sentence *)calloc(sen_size, sizeof(Sentence));
	text.sen[i].str = (wchar_t *)calloc(str_size, sizeof(wchar_t));
	while (1) {
		if (j == str_size - 1) {
			str_size *= 2;
			text.sen[i].str = (wchar_t *)realloc(text.sen[i].str, str_size * sizeof(wchar_t));
		}
		c = getwchar();
		if (c == L'.') {
			if (i == sen_size - 1) {
				sen_size *= 2;
				text.sen = (Sentence *)realloc(text.sen, sen_size * sizeof(Sentence));
			}
			text.sen[i].str[j++] = c;
			text.sen[i].str[j] = L'\0';
			i++; j = 0;
			str_size = INIT_STR_SIZE;
			text.sen[i].str = (wchar_t *)calloc(str_size, sizeof(wchar_t));
			while (iswspace(c = getwchar()) && c != L'\n');
		}
		if (c == L'\n') break;
		text.sen[i].str[j++] = c;
	}
	if (i != 0)
		text.len = i;
	else return (Text){NULL, 0};
	return text;
}


void text_free(Text *text) 
{
	for (size_t i = 0; i < text->len; i++) {
		free(text->sen[i].str);
	}
	free(text->sen);
}


void print_text(Text text) 
{
	for (size_t i = 0; i < text.len; i++) {
		wprintf(L"%ls ", text.sen[i].str);
	}        
	wprintf(L"\n");
}


void text_cleaner(Text *text) 
{
	for (size_t i = 0; i < text->len; i++)
		for (size_t j = i + 1; j < text->len; j++)
			if (!wcscasecmp(text->sen[i].str, text->sen[j].str)) {
				for (size_t k = j; k < text->len - 1; k++)
					text->sen[k].str = text->sen[k+1].str;
				text->len--;
				j--;
			}
}