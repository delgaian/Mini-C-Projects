/*Scaled up version of the histogram program*/
#include <stdio.h>
#define MAXSTARNUM 50
#define MAXENTRIES 50
#define NUMTOCLEAR 25
#define VOID int

extern double FindScalingFraction();

int main() {
    int entryCount; /*Looping variable*/

    FILE *output; /*output file*/

    int numEntries; /*Total number of entries*/

    double scalingMultiplier; /*Scaling value*/

    double value[MAXENTRIES]; /*All values user enters*/

    if((output = fopen("Histogram3", "w")) == 0) {
        fprintf(stderr, "Error, cannot open file.\n");
        exit(0);
    }
    /*clear screen if there is an error*/
    clearScreen();

    printf("How many entries would you like in the histogram? > ");
    scanf("%d", &numEntries);
    /*Trap invalid entires*/
    while(numEntries > MAXENTRIES || numEntries < 1) {
        printf("\n\tPlease enter a number between 1 and %d\n", MAXENTRIES);
        printf("\nHow many entries would you like in the histogram? > ");
        scanf("%d", &numEntries);
    }

    /*Get the entries*/

    for(entryCount = 0; entryCount < numEntries; entryCount++) {
        printf("\nFor entry %d, please give a value: ", entryCount + 1);
        scanf("%lf", &value[entryCount]);
    }

    scalingMultiplier = FindScalingFraction(value, numEntries, MAXSTARNUM);
    /*Write the histogram to stdout and to the output file*/
    writeHistogram(stdout, value, numEntries, scalingMultiplier);
    writeHistogram(output, value, numEntries, scalingMultiplier);
    fclose(output);
 

}
/*Function that clears the screen if there is an error*/
void clearScreen() {
    int counter;

    for(counter = 0; counter < NUMTOCLEAR; counter++) {
        putchar('\n');
    }
}
/*Returns the multiplier that scales every element in the inputArr to be smaller than the maximum size*/
double FindScalingFraction(inputArr, numElements, maxSize) 
double inputArr[];
int maxSize;
int numElements;
{
    int curElement;
    double maxElement;

    /*Iterate through each element and check if it is larger than the previous maximum element and if so, 
    make that element the new max element*/

    for(curElement = 0, maxElement = 0.0; curElement < numElements; curElement++) {
        maxElement = (inputArr[curElement] > maxElement) ? inputArr[curElement] : maxElement;
    }

    /*Scaling multiplier is the maximum number of elements divided by the maximum value in the array*/

    return((double)maxSize / maxElement);
}
/*Prints a ruler to the output file to measure the histogram*/
void printRuler(targetFile)
FILE *targetFile;
{
    int ruler;
    fprintf(targetFile, "\nScale | ");
    for(ruler = 0; ruler < 10; ruler++) {
        fprintf(targetFile, "----+");
    }
}
/*Function to write the histogram to the output file and to stdout*/
void writeHistogram(targetFile, inputArr, numElements, scalingFactor)
double inputArr[];
int numElements;
double scalingFactor;
FILE *targetFile;
{
    int elementCount;
    int numStarsToWrite;
    int starCount;

    /*Cycle through each input element and print each on its own line*/

    for(elementCount = 0; elementCount < numElements; elementCount++) {
        /*first print the number to write on the line then a bar to signal where the graph will start*/

        fprintf(targetFile, "%5.1f | ", inputArr[elementCount]);

        /*calculate the number of stars to write by using the scaling factor. multiplication is done in floating point but
        final result is converted to an int*/

        numStarsToWrite = (int)(inputArr[elementCount] * scalingFactor);
        /*Write the stars and a newline*/

        for(starCount = 0; starCount < numStarsToWrite; starCount++) {
            putc('*', targetFile);
        }

        fprintf(targetFile, "\n");
    }

    /*Print the ruler line at the end*/
    printRuler(targetFile);
}