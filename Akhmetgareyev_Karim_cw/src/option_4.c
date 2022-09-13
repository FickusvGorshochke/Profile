#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h>

#include "header/structures.h"
#include "header/functions.h"
#include "header/defines.h"



void swap(Text *text)
{
	int flag = 0;
	wchar_t prev[MAX_WORD_LEN], new[MAX_WORD_LEN];
	
	wprintf(PREV_WORD_PLEASE);
	fgetws(prev, 200, stdin);
	prev[wcslen(prev) - 1] = L'\0';
	for (size_t i = 0; i < wcslen(prev); i++)
		if (!iswalpha(prev[i])) {
			wprintf(INPUT_ERROR);
			flag = 1;
			return;
		}

	wprintf(NEW_WORD_PLEASE);
	fgetws(new, 200, stdin);
	new[wcslen(new) - 1] = L'\0';
	for (size_t i = 0; i < wcslen(new); i++)
		if (!iswalpha(new[i])) {
			wprintf(INPUT_ERROR);
			flag = 1;
			return;
		}

	if (!flag) {
		for (size_t i = 0; i < text->len; i++) {
			if (swap_in_string(text->sen[i].str, prev, new)) flag = 1;
		}
		if (!flag) wprintf(SWAP_ERROR);
        else wprintf(SWAP_SUCCESS);
	}
}


int swap_in_string(wchar_t *str, wchar_t *prev, wchar_t *new) 
{
    int flag = 0;
    size_t prev_len = wcslen(prev), new_len = wcslen(new);
    for (size_t i = 0; str[i + prev_len - 1] != L'\0'; i++) {
        if (is_sep_word(str, str+i, prev)) {
            flag = 1;
            if (new_len > prev_len) {
                str = (wchar_t *)realloc(str, (wcslen(str) + new_len * 10) * sizeof(wchar_t));
                memmove(str + i + new_len, str + i, (wcslen(str) - i + 2) * sizeof(wchar_t));
            }
            else {
                memmove(str + i + new_len, str + i + prev_len, (wcslen(str) + 1 - i - prev_len) * sizeof(wchar_t));
            }
            wcsncpy(str + i, new, new_len);
        }
    }
    return flag;
}


int is_sep_word(wchar_t *str, wchar_t *p, wchar_t *word) 
{
    size_t len = wcslen(word);
    return ((!wcsncasecmp(word, p, len)) && ((p == str && wcschr(L" ,.", *(str + len))) || 
                                          wcschr(L" ,.\0", *(p + len)) && wcschr(L" ,", *(p - 1))));
}

