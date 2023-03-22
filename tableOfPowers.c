/*program that prints out a table of powers*/

/*Project from "C By Dissection" from Ali Kelley and Ira Pohl*/
#include <stdio.h>



int main()
{
    int i;
    int LIMIT = 0;
    printf("Enter the limit of the table of powers: ");
    scanf("%d", &LIMIT);
    while(LIMIT <= 0) {
        printf("Error, please enter a positive number: ");
        scanf("%d", &LIMIT);
    }

    printf("\n%s\n%s\n%7s%12s%12s%12s%12s\n\n", "A table of powers", "------------------------", "integer", "square", "cube", "quartic", "quintic");

    for(i = 1; i <=LIMIT; ++i) {
        printf("%7d%12d%12d%12d%12d\n", i, i*i, i*i*i, i*i*i*i, i*i*i*i*i);
    }
}