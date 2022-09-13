#include <stdio.h>
#include <stdlib.h>
#include <wctype.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>

#include "header/structures.h"
#include "header/functions.h"
#include "header/defines.h"


int main() 
{
	setlocale(LC_CTYPE, "");

	wprintf(GREETING);
	Text text = text_input();
	while (!text.len) {
		wprintf(INPUT_ERROR);
		wait();
		wprintf(GREETING);
		text = text_input();
	}
	text_cleaner(&text);

	while(menu(&text));
	
	text_free(&text);
	return 0;
}

// Меню
int menu(Text *text) 
{        
	wprintf(HELP_MESSAGE);
	int choice;
	choice = (int)getwchar() - (int)L'0';
	if (getwchar() != L'\n'){
		while(getwchar() != L'\n');
		choice = -1;
	}
	switch (choice)
	{
	case 1: 
		show_anagrams(*text);
		wait();
		CONTINUE; 
	case 2: 
		uppercase_sort(text);
		wait();
		CONTINUE; 
	case 3: 
		vowels_to_next_two(text);
		wait();
		CONTINUE; 
	case 4: 
		swap(text);
		wait();
		CONTINUE; 
	case 5:
		print_text(*text);
		wait();
		CONTINUE; 
	case 0: 
		wprintf(L"\nВыход из программы!|Exiting the program!\n"); 
		EXIT;
	default: 
		wprintf(L"\nНеверный номер.|Wrong number.\n");
		wait();
		CONTINUE;
	}
}


void wait() 
{
	wprintf(WAITING_MESSAGE);
	while(getwchar() != '\n');
}
