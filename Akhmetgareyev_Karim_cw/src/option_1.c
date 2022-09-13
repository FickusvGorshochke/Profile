#include <stdlib.h>
#include <wctype.h>
#include <wchar.h>

#include "header/structures.h"
#include "header/functions.h"
#include "header/defines.h"


void show_anagrams(Text text) 
{
	size_t *anagram_flags = (size_t*)calloc(text.len, sizeof(size_t));

	size_t max_flag = 0;
	for (size_t i = 0; i < text.len; i++) {
		if (anagram_flags[i]) continue;
		for (size_t j = i + 1; j < text.len; j++)
			if (is_anagram(text.sen[i], text.sen[j])) {
				if (!anagram_flags[i]) max_flag++;
				anagram_flags[i] = max_flag;
				anagram_flags[j] = max_flag;
			}
	}
	if (!max_flag) wprintf(ANAGRAM_ERROR);
	size_t k = 0;
	while (k++ != max_flag) {
		wprintf(L"Анаграммы (%d):\n", k);
		for (size_t i = 0; i < text.len; i++)
			if (anagram_flags[i] == k)
				wprintf(L"\t%ls\n", text.sen[i].str);
	}
	free(anagram_flags);
}


int is_anagram(Sentence sent_1, Sentence sent_2) 
{
	wchar_t *new_str_1 = (wchar_t *)malloc((wcslen(sent_1.str)+1) * sizeof(wchar_t));
	wcscpy(new_str_1, sent_1.str);
	clear_wstr(new_str_1);

	wchar_t *new_str_2 = (wchar_t *)malloc((wcslen(sent_2.str)+1) * sizeof(wchar_t));
	wcscpy(new_str_2, sent_2.str);
	clear_wstr(new_str_2);

	if (wcslen(new_str_1) != wcslen(new_str_2)) {
		free(new_str_1); free(new_str_2); 
		return 0;
    }
	qsort(new_str_1, wcslen(new_str_1), sizeof(wchar_t), wlexgraphic_cmp);
	qsort(new_str_2, wcslen(new_str_2), sizeof(wchar_t), wlexgraphic_cmp);
	int result = !wcscmp(new_str_1, new_str_2);
	free(new_str_1); free(new_str_2);
	return result;
}


void clear_wstr(wchar_t *str) 
{
	size_t k = 0;
	for (size_t i = 0; i < wcslen(str); i++) {
		if (iswalnum(str[i])) {
			str[k++] = towupper(str[i]);
		}
	}
	str[k] = L'\0';
} 

int wlexgraphic_cmp(const void *a, const void *b) 
{
	wchar_t aa = *(wchar_t *)a;
	wchar_t bb = *(wchar_t *)b;
	if (aa <  bb) return -1;
	if (aa == bb) return 0;
	if (aa >  bb) return 1;
	return -1;
}

