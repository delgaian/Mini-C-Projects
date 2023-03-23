/*program that converts from Fahrenheit to Celsius*/

/*From "The C Programming Tutor" by Leon A. Wortman and Thomas O. Sidebottom*/

#include <stdio.h>
#define ENDINGDEG 300
#define INCREMENT 5
#define STARTINGDEG 0

int main() {
    float degreeCel;

    int degreeFahr;
    printf("\nTable of Fahrenheit to Celsius \n");
    printf("--------------------------------\n");
    for (degreeFahr == STARTINGDEG; degreeFahr < ENDINGDEG; degreeFahr += INCREMENT) {
        degreeCel = (5.0 / 9.0) * ((float)degreeFahr - 32.0);
        
        printf("Fahrenheit: %5d Celsius: %6.2f\n", degreeFahr, degreeCel);
    }
}