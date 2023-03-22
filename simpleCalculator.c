#include <stdio.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0


main () {
    int badOperator;
    int dummy;
    float firstNum;
    int operation;
    float result;
    float secondNum;

    do {
        badOperator = FALSE;
        printf("Pick an operation: +, -, *, /: ");
        operation = getchar();
        printf("Enter your first number: ");
        scanf("%f", &firstNum);
        printf("Enter your second number: ");
        scanf("%f", &secondNum);
        switch (operation) {
            case '+': result = firstNum + secondNum;
                      break;
            case '-': result = firstNum - secondNum;
                      break;
            case '*': result = firstNum * secondNum;
                break;
            case '/': result = firstNum / secondNum;
                break;
            default:
                printf("You enter an invalid operator!\n");
                badOperator = TRUE;
                break;
        }
        // Throw away the extra character
        dummy = getchar();
        if(badOperator == FALSE){
            printf("Your calculation is: %4.1f\n", result);
        }
    } while (continueCalculating());

    // continue calculating while the user chooses 'y'

}

int continueCalculating() {
    int dummy;
    int response;

    printf("Would you like another calculation? (Y/N): ");
    do {
        response = getchar();
        response = tolower(response);
        if (response != 'y' && response != 'n') {
            printf("Enter either 'Y' or 'N': ");
            //throw out extra char 
            response = getchar();
        }

    } while (response != 'y' && response != 'n');
    //throwaway extra char before returning
    dummy = getchar();
    return ((response == 'y') ? TRUE : FALSE);
    //continue working

}