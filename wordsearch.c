#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declarations of the two functions you will implement
// Feel free to declare any helper functions
void printPuzzle(char **arr, int n);
void searchPuzzle(char **arr, int n, char **list, int listSize);

// Main function, DO NOT MODIFY (except line 52 if your output is not as expected -- see the comment there)!!!
int main(int argc, char **argv)
{
	int bSize = 15;
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <puzzle file name>\n", argv[0]);
		return 2;
	}
	int i, j;
	FILE *fptr;
	char **block = (char **)malloc(bSize * sizeof(char *));
	char **words = (char **)malloc(50 * sizeof(char *));

	// Open file for reading puzzle
	fptr = fopen(argv[1], "r");
	if (fptr == NULL)
	{
		printf("Cannot Open Puzzle File!\n");
		return 0;
	}

	// Read puzzle block into 2D arrays
	for (i = 0; i < bSize; i++)
	{
		*(block + i) = (char *)malloc(bSize * sizeof(char));

		fscanf(fptr, "%c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", *(block + i), *(block + i) + 1, *(block + i) + 2, *(block + i) + 3, *(block + i) + 4, *(block + i) + 5, *(block + i) + 6, *(block + i) + 7, *(block + i) + 8, *(block + i) + 9, *(block + i) + 10, *(block + i) + 11, *(block + i) + 12, *(block + i) + 13, *(block + i) + 14);
	}
	fclose(fptr);

	// Open file for reading word list
	fptr = fopen("states.txt", "r");
	if (fptr == NULL)
	{
		printf("Cannot Open Words File!\n");
		return 0;
	}

	// Save words into arrays
	for (i = 0; i < 50; i++)
	{
		*(words + i) = (char *)malloc(20 * sizeof(char));
		fgets(*(words + i), 20, fptr);
	}

	// Remove newline characters from each word (except for the last word)
	for (i = 0; i < 49; i++)
	{
		*(*(words + i) + strlen(*(words + i)) - 2) = '\0'; // Change -2 to -1 if line 58 outputs words with the last character missing
	}

	// Print out word list
	printf("Printing list of words:\n");
	for (i = 0; i < 50; i++)
	{
		printf("%s\n", *(words + i));
	}
	printf("\n");

	// Print out original puzzle grid
	printf("Printing puzzle before search:\n");
	printPuzzle(block, bSize);
	printf("\n");

	// Call searchPuzzle to find all words in the puzzle
	searchPuzzle(block, bSize, words, 50);
	printf("\n");

	// Print out final puzzle grid with found words in lower case
	printf("Printing puzzle after search:\n");
	printPuzzle(block, bSize);
	printf("\n");

	return 0;
}

void printPuzzle(char **arr, int n)
{
	// This function will print out the complete puzzle grid (arr). It must produce the output in the SAME format as the samples in the instructions.
	// Your implementation here
	int i, j, k;


	//rows
	for ( i = 0; i < n; i++)
	{
		//columns
		for ( j = 0; j < n; j++)
		{

			printf("%c", *(*(arr + i) + j));
		}
		printf("\n");
	}
}

void searchPuzzle(char **arr, int n, char **list, int listSize)
{
	// This function checks if arr contains words from list. If a word appears in arr, it will print out that word and then convert that word entry in arr into lower case.
	// Your implementation here
	int counter = 0;
	int number = 4;
	char *inrow = (char*)malloc(number * sizeof(char*));
	int *words = (int*)malloc(4 * sizeof(int*));
	//printf("hello world");
	// left to right search
	for(int i = 0; i < n; i++){ // the row its on
		for(int j = 0; j < 12; j++){ // the column its on, so the number in the ith array// how many numbers we will skp
			if(number == -23151185185){
				// this is dead code but can be used for searching at different inncrements in columns
			}
			else{
				// find the word
				for(int k = 0; k < number; k++){ // for every 3 in row
					if(k == 0){
						*(inrow + k) = (char)*(*(arr + i) + (j + k));	
					}
					if(k != 0){
						//char tolower = ((char)*(*(arr + i) + (j + k)));
						//printf("%c", tolower + 32);
						*(inrow + k) = ((char)*(*(arr + i) + (j + k)))+32;
					}
				}
				//for(int k = 0; k < number; k++){ // for every 3 in row
					//printf("%c", *(inrow + k));
				//}

				//checking for the word in the list
				for(int l = 0; l < listSize; l++){ // row of word in wordlist
					counter = 0;
					if(*(inrow + 0) == (char)*(*(list + l) + 0 )){
							for(int m = 0; m < number; m++){
							//printf("passed check 1\n");
							if(*(inrow + m) == (char)*(*(list + l) + m )){
								//printf("%d------", counter);
							counter++;
							//printf("%d------", counter);
							//printf("\n");
									if(counter == number){
									printf("word found: ");
										for(int length = 0; (char)*(*(list + l) + length) != NULL; length++){
											printf("%c", (char)*(*(list + l) + length));
										}
										printf("\n");
									}
							}
						}	
					}	
					else{

					}						
				}
			}
		}
	}
	
	// From top down
	for(int i = 0; i < n; i++){ // the row its on
		for(int j = 0; j < 12; j++){ // the column its on, so the number in the ith array// how many numbers we will skp
			if(number == -23151185185){
				// this is dead code but can be used for searching at different inncrements in columns
			}
			else{
				// find the word
				for(int k = 0; k < number; k++){ // for every 3 in row
				//printf("i made it here hello\n");
					if(k == 0){
						*(inrow + k) = (char)*(*(arr + (j + k)) + (i));	
					}
					if(k != 0){
						//printf("i made it here hello3\n");
						//char tolower = ((char)*(*(arr + i) + (j + k)));
						//printf("%c", tolower + 32);
						//printf("i is %d ", i);
						//printf("j is %d ", j);
						//printf("k is %d ", k);
						*(inrow + k) = ((char)*(*(arr + (j + k)) + (i))) + 32;
						//printf("i made it here hello3.1\n");
					}
						//printf("i made it here hello4\n");
				}
				//for(int k = 0; k < number; k++){ // for every 3 in row
					//printf("%c", *(inrow + k));
				//}

				//checking for the word in the list
				//printf("i made it here hello 1\n");
				for(int l = 0; l < listSize; l++){ // row of word in wordlist
				//printf("i made it here hello 2\n");
					counter = 0;
					if(*(inrow + 0) == (char)*(*(list + l) + 0 )){
							for(int m = 0; m < number; m++){
							//printf("i was here \n");
							if(*(inrow + m) == (char)*(*(list + l) + m )){
								//printf("%d------", counter);
							counter++;
							//printf("%d------", counter);
							//printf("\n");
									if(counter == number){
										//printf("i was here 1 \n");
										printf("word found: ");
										for(int length = 0; (char)*(*(list + l) + length) != NULL; length++){
											printf("%c", (char)*(*(list + l) + length));
										}
										printf("\n");
									}
							}
						}	
					}	
					else{

					}						
				}
				//printf("i was here 3\n");
			}
			//printf("i was here 4 \n");
			//printf("this is j %d ", j);
		}
		//printf("i was here 5 \n");
	}
	
	// From Bottom up (not complete)
	for(int i = 0; i < n; i++){ // the row its on
		for(int j = 0; j < 12; j++){ // the column its on, so the number in the ith array// how many numbers we will skp
			if(number == -23151185185){
				// this is dead code but can be used for searching at different inncrements in columns
			}
			else{
				// find the word
				for(int k = 0; k < number; k++){ // for every 3 in row
				//printf("i made it here hello\n");
					if(k == 0){
						*(inrow + k) = (char)*(*(arr + (j + k)) + (i));	
					}
					if(k != 0){
						//printf("i made it here hello3\n");
						//char tolower = ((char)*(*(arr + i) + (j + k)));
						//printf("%c", tolower + 32);
						//printf("i is %d ", i);
						//printf("j is %d ", j);
						//printf("k is %d ", k);
						*(inrow + k) = ((char)*(*(arr + (j + k)) + (i))) + 32;
						//printf("i made it here hello3.1\n");
					}
						//printf("i made it here hello4\n");
				}
				//for(int k = 0; k < number; k++){ // for every 3 in row
					//printf("%c", *(inrow + k));
				//}

				//checking for the word in the list
				//printf("i made it here hello 1\n");
				for(int l = 0; l < listSize; l++){ // row of word in wordlist
				//printf("i made it here hello 2\n");
					counter = 0;
					if(*(inrow + 0) == (char)*(*(list + l) + 0 )){
							for(int m = 0; m < number; m++){
							//printf("i was here \n");
							if(*(inrow + m) == (char)*(*(list + l) + m )){
								//printf("%d------", counter);
							counter++;
							//printf("%d------", counter);
							//printf("\n");
									if(counter == number){
										//printf("i was here 1 \n");
										printf("word found: ");
										for(int length = 0; (char)*(*(list + l) + length) != NULL; length++){
											printf("%c", (char)*(*(list + l) + length));
										}
										printf("\n");
									}
							}
						}	
					}	
					else{

					}						
				}
				//printf("i was here 3\n");
			}
			//printf("i was here 4 \n");
			//printf("this is j %d ", j);
		}
		//printf("i was here 5 \n");
	}
}

