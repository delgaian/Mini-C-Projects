#include <stdio.h>

void main() {
    int raw_response;
    char response;
    printf("Do you like dick? (Y or N): ");

    raw_response = getchar();

    response = raw_response;

    if(response = 'Y') {
        printf("Just wait until you see what you can do!");
    }
    if(response == 'N') {
        printf("Keep trying! I bet you'll change your mind.\n")
    }
}