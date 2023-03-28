/*Program that creates histogram for user and saves it to a file*/
/*From "The C Programming Tutor" by Leon A. Wortman and Thomas O. Sidebottom*/

#include <stdio.h>
/*Maximum value that a entry can have*/
#define MAXVAL 100.0
/*Number that will clear the histogram*/
#define CLEARNUM 25
#define VOID int
int main() {
    int entryCount; /*Looping variable*/

    int numEntries; /*number of entries in histogram*/

    FILE *outputFile; /*File that the histogram will output to*/

    float value; /*Value for entry*/

    if((outputFile = fopen("histogram4.txt", "w")) == 0 ) {
        fprintf(stderr, "Error - Unable to open output file.\n");
        exit(0);
    }

    clearScreen();
    /*prompt user for histogram entries*/
    printf("How many entries would you like to make in your histogram? > ");
    /*Gather input*/
    scanf("%d", &numEntries);

    for(entryCount = 0; entryCount < numEntries; entryCount++) {
        printf("\nFor Entry %d, give a value between 0 and 100 > ", entryCount + 1);
        scanf("%f", &value);
        /*handle invalid values*/
        while (value > MAXVAL) {
            printf("\n\t The max number you can enter is 100.");
            printf("\n\tPlease re-enter a smaller value > ");
            scanf("%f", &value);
        }

        writeHistogram(stdout, value);
        writeHistogram(outputFile, value);
    }

    printRuler(stdout, value);
    printRuler(outputFile);


}

/*function to clear screen*/
void clearScreen() {
    int counter;

    for(counter = 0; counter < CLEARNUM; counter++) {
        putchar('\n');
    }
}
/*Writes ruler line to target file*/
void printRuler(targetFile)
FILE *targetFile;
{
    fprintf(targetFile, "      | ----+----+----+----+----+");
    fprintf(targetFile, "----+----+----+----+----|\n");
}
/*Writes the value and bar to the target file*/
void writeHistogram(targetFile, numToWrite)
float numToWrite;
/*File to write the output to*/
FILE *targetFile;
{
    int count;
    fprintf(targetFile, "%5.f | ", numToWrite);
    /*Iterate through the value and denote each by 2. Each "-" denotes a value of 2. each "+" denotes a value of 10*/
    for(count = 0; count < (int)numToWrite/2; count++) {
        putc('*', targetFile);
    }
    fprintf(targetFile, "\n");
    
}