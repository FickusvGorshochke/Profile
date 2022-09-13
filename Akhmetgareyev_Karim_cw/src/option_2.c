#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>

#include "header/structures.h"
#include "header/functions.h"
#include "header/defines.h"


void uppercase_sort(Text *text) 
{
	qsort(text->sen, text->len, sizeof(Sentence), wuppercase_cmp);
	wprintf(SORT_SUCCESS);
}


int wuppercase_cmp(const void *sen1, const void *sen2) 
{
	wchar_t *string1 = (*(Sentence *)sen1).str;
	wchar_t *string2 = (*(Sentence *)sen2).str;
	size_t uprs1 = count_uppers(string1);
	size_t uprs2 = count_uppers(string2);
	if (uprs1 <  uprs2) return -1;
	if (uprs1 == uprs2) return 0;
	if (uprs1 >  uprs2) return 1;
	return -1;
}


size_t count_uppers(wchar_t *str) 
{
	size_t res = 0;
	for (size_t i = 0; i < wcslen(str); i++) {
		if (iswupper(str[i])) res++;
	}
	return res;
}

