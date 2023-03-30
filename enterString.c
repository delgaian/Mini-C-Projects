/*Program that prompts user to enter a line of characters and returns the string to stdout*/

/*From "The C Programming Tutor" Leon A. Wortman and Thomas O. Sidebottom*/

#include <stdio.h>
#define STRINGLENGTH 225

int main() {
    char inputString[STRINGLENGTH];

    printf("Please enter a sentence and hit ENTER.\n");
    fgets(inputString, STRINGLENGTH, stdin);
    printf("\nYour sentence is > %s\n", inputString);
    printf("Again, your sentence is > ");
    fputs(inputString, stdout); 
}