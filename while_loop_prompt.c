#include <stdio.h>
#include <ctype.h>

void main() {
    int response;

    printf("Are you feeling okay? (Y/N): ");
    response = getchar();
    response = tolower(response);

    while (response != 'y' && response != 'n') {
        //get rid of the extra character until we reach 'y' or 'n'
        response = getchar();
        printf("\nYou entered an incorrect letter.\n");
        printf("Enter only 'Y' or 'N': ");
        response = getchar();
        response = tolower(response);
    }

    if (response == 'y') {
        printf("I'm Glad!");
    } else {
        printf("I'm sorry");
    }
}