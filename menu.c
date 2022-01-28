#include <stdio.h>

/**
 * Prints out the Word Stats menu options and scans the user input.
 * @return int the option the user selected
 */
int getMenuOption()
{
	int resp = 0;
	// TODO
	printf("***WORD STATS MENU***\nEnter 1 to print vowel and consonant frequency.\nEnter 2 to print word count.\nEnter 3 to print histogram.\nEnter 4 to return to inputting more strings.\nEnter 5 to quit.\n");
	scanf("%d", &resp);
	return resp;
}
