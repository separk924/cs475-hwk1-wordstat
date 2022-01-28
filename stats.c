
#include "stats.h"
#include <stdio.h>
#include <string.h>

#define LNUM 25 /* Number of letters */
#define MAX_INPUT_LEN 128 /** maximum length of input users can enter */

/**
 * Initializes the statistics structure
 * @param st an uninitialized WordStats struct
 * @return an initialized WordStats struct 
 */
WordStats initStats(WordStats st)
{
	// TODO initialize all fields in the st struct before returning it
	int histo[26] = 0;
	int wordCount = 0;
	int vowelCount = 0;
	int consonantCount = 0;
	return st;
}

/**
 * Updates vowels and consonants in the struct
 * @param st WordStats structure
 * @param str the user-input string
 * @return an updated WordStats struct 
 */
WordStats updateVowelCons(WordStats st, const char str[])
{
	// TODO - update the vowel and consonant count
	//        in the st struct before returning it
	int len = strlen(str);
	for(int i=0;i<len;i++){
		if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' ||
			str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U'){
				st.vowelCount++;
		}else{
				st.consonantCount++;
		}
	}
	return st;
}

/**
 * Updates word count in the struct
 * @param st 
 * @param str 
 * @return an updated WordStats struct 
 */
WordStats updateWordCount(WordStats st, const char str[])
{
	// TODO - update the word count in the st struct before returning it
	int len = strlen(str);
	for(int i=0;i<len;i++){
		if(str[i]==' '){
			st.wordCount++;
		}
	}
	return st;
}

/**
 * Outputs vowel and consonant stats
 * @param st WordStats structure
 */
void printVowelConsFreq(WordStats st)
{
	// TODO: print vowel and consonant frequency
	int vCount = st.vowelCount;
	int cCount = st.consonantCount;
	int wCount = st.wordCount;
	int vPerc = vCount/wCount;
	int cPerc = cCount/wCount;
	printf("Vowels = %d (%0.2f), Consonants = %d (%0.2f)\n", vCount, vPerc, cCount, cPerc);
}

/**
 * Outputs word count
 * @param st WordStats structure
 */
void printWordCount(WordStats st)
{
	// TODO: prints word count
	int wCount = st.wordCount;
	printf("Words: %d\n", wCount);
}

/**
 * Outputs histogram vertically
 * @param st WordStats structure
 */
void printHistogram(WordStats st, const char str[])
{
	// TODO: Prints vertical histogram
	int alphabet[LNUM] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	int lCount[LNUM];

	for(int k=0;k<LNUM;k++){ // initialize all letters to 0
		lCount[k] = 0;
	}

	int len = strlen(str); // length of the string

	for(int i=0;i<LNUM;i++){ // counts the number of times a letter appears
		char letter = alphabet[i];
		for(int j=0;j<len;j++){
			if(str[j]==alphabet[i]){
				lCount[i]++;
			}
		}
	}

	for(int i=MAX_INPUT_LEN;i>=1;--i){ // prints vertical histogram
		for(int j=0; j<=lCount[i];++j){
			if(i<=lCount[j]){
				printf('*');
			}else{
				printf(' ');
			}
			printf('\n');
		}
	}
	for(int l=0;l<LNUM;l++){ // prints out the alphabet
		printf("%c ", alphabet[l]);
	}
	for(int m=0;m<LNUM;m++){ // prints out how many times the letters appear
		printf("%d ", lCount[m]);
	}
}