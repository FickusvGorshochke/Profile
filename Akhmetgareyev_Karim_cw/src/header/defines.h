#define CONTINUE return 1;
#define EXIT return 0;

#define VOWELS L"AEIOUYАЕЁИОУЫЭЮЯ"
#define MAX_WORD_LEN 200
#define INIT_STR_SIZE 32

#define WAITING_MESSAGE L"\nДля продолжения нажмите ENTER...|To continue, press ENTER...\n"
#define GREETING L"\nПожалуйста, введите текст|Please, enter the text:\n\t"
#define PREV_WORD_PLEASE L"Введите слово, которое подлежит замене|Enter the word to be replaced: "
#define NEW_WORD_PLEASE L"Введите слово, на которое нужно заменить|Enter the word you want to replace: "
#define HELP_MESSAGE L"\nВыберите номер опции|Select the option number:\n\t1. Вывести все предложения-анаграммы|Output all anagram sentences\n\t2. Отсортировать предложения по количеству заглавных букв|Sort sentences by the number of uppercase letters\n\t3. Заменить все гласные буквы на две следующие за ней по алфавиту|Replace all vowel letters with the two following it alphabetically\n\t4. Заменить все слова А на слова Б|Replace all words A with words B\n\t5. Распечатать текст|Print the text\n\t0. Выйти|Exit\n>>>"

#define ANAGRAM_ERROR L"\nАнаграмм не найдено.|No anagrams found.\n"
#define SWAP_ERROR L"\nТекст не был изменён.|The text has not been changed.\n"
#define INPUT_ERROR L"\nВвод некорректен.|The input is incorrect.\n"
#define VOWELS_ERROR L"\nВ тексте нет гласных букв.|There are no vowel letters in the text."

#define SORT_SUCCESS L"\nТекст отсортирован.|The text is sorted.\n"
#define SWAP_SUCCESS L"\nСлова успешно заменены|Words have been successfully replaced\n"
#define VOWELS_SUCCESS L"\nГласные успешно заменены|Vowels have been successfully replaced\n"

