#include <stdio.h>

void main() {
    int count;

    printf("Table of squares: \n\n");
    for (count = 1; count <= 100; count = count + 1)
        printf("Number: %d Square: %d\n", count, count * count);
}