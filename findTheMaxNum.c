#include <stdio.h>
int main() {
    int numOfNums, index;
    float max, x;

    printf("This program will find the maximum number from the amount of numbers you enter!\n");

    printf("To start, how many numbers would you like to enter?: ");
    scanf("%d", &numOfNums);

    while (numOfNums <= 0){
        printf("Invalid input. Please enter a positive number\n\n");

        printf("How many numbers would you like to enter?: ");
        scanf("%d", &numOfNums);

    }

    printf("Give me a list of %d numbers:\n", numOfNums);
    scanf("%f", &x);
    max = x;
    index = 1;

    while (index < numOfNums) {
        scanf("%f", &x);
        if (max < x) {
            max = x;
        }
        ++index;
    }
    printf("\n The maximum value in your list is: %g\n\n", max);

}