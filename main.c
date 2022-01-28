#include <stdio.h>
#include <string.h>
#include "stats.h"
#include "menu.h"

#define MAX_INPUT_LEN 128 /** maximum length of input users can enter */

/**
 * Main function
 * 
 * @param argc the number of command line arguments (ignore for this assignment)
 * @param argv an array of command line arguments (ignore for this assignment)
 */
int main(int argc, char **argv)
{
	WordStats stats;
	char input[MAX_INPUT_LEN]; //holds user-input string
	char allInput[MAX_INPUT_LEN];
	// TODO: repeatedly print menu options and prompt for an option
	// TODO: display the proper output
	printf("Enter strings (# to stop):\n");
	fgets(input, MAX_INPUT_LEN, stdin);
	strcat(allInput, input);
	// while(input!='#'){
	// 	fgets(input, MAX_INPUT_LEN, stdin);
	// 	strcat(allInput, input);
	// }
	// int resp = getMenuOption();
	// switch(getMenuOption()){
	// 	case '1' :
	// 		updateVowelCons(stats, allInput);
	// 		printVowelConsFreq(stats);
	// 		break;
	// 	case '2' :
	// 		printWordCount(stats);
	// 		break;
	// 	case '3' :
	// 		printHistogram(stats, allInput);
	// 		break;
	// 	case '4' :
	// 		printf("Enter strings (# to stop):\n");
	// 		fgets(input, MAX_INPUT_LEN, stdin);
	// 		strcat(allInput, input);
	// 		while(input!='#'){
	// 			fgets(input, MAX_INPUT_LEN, stdin);
	// 			strcat(allInput, input);
	// 		};
	// 		break;
	// 	case '5' :
	// 		break;
	// 	default :
	// 	printf("Error: Unknown option %d. Try again.\n", input);
	// }

	do{
		if(getMenuOption() == '1'){
			updateVowelCons(stats, allInput);
			printVowelConsFreq(stats);
		}else if(getMenuOption() == '2'){
			printWordCount(stats);
		}else if(getMenuOption() == '3'){
			printHistogram(stats, allInput);
		}else if(getMenuOption() == '4'){
			printf("Enter strings (# to stop):\n");
			fgets(input, MAX_INPUT_LEN, stdin);
			strcat(allInput, input);
			while(input!='#'){
				fgets(input, MAX_INPUT_LEN, stdin);
				strcat(allInput, input);
			};
		}else{
			printf("Error: Unknown option %d. Try again.\n", input);
		}
	}while(getMenuOption()=='5');
	printf("Exiting...\n");
	return 0;
}
