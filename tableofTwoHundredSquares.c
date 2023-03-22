#include <stdio.h>
#define STARTNUM 1
#define ENDNUM 200

void main() {
    int count;
    long square;

    printf("Table of 200 squares\n\n");
    for (count = STARTNUM; count <= ENDNUM; count++) {
        square = (long)count * (long)count;
        printf("Number %d  Square: %ld\n", count, square);
    }
}