#include <stdio.h>
/*program that displays a histogram based on what the user enters*/

/*From "The C Programming Tutor" by Leon A. Wortman and Thomas O. Sidebottom*/
int main() {
    int entryCount; /*looping variable entry number of the user*/
    int numEntries; /*total number of user entries*/
    int startCount; /*counter of current number of stars*/
    int value; /*value of specific entry*/

    printf("How many entries would you like in the histogram? > ");
    scanf("%d", &numEntries);

    for (entryCount = 0; entryCount < numEntries; entryCount++) {
        printf("\nFor Entry %d, type a value between 0 and 100: ", entryCount + 1);
        scanf("%d", &value);

        /*Display value then a bar to represent the base of the graph*/

        printf("%d | ", value);

        /*Display half the number of stars according to the value to fit up to 100 stars on a single line*/

        for (startCount = 0; startCount < value / 2; startCount++) {
            printf("*");
        }

        printf("\n");
    }
}