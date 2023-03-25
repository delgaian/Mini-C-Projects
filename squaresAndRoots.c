#include <stdio.h>
#include <math.h>
#define STARTNUM 1
#define ENDNUM 200

/*explicitly call the square root function from the math.h header*/
extern double sqrt();

int main() {
    int count;
    double root;
    long square;

    printf("\nTable of squares and square roots\n");
    printf("-----------------------------------\n");

    for(count = STARTNUM; count <= ENDNUM; count++) {
        square = (long)count * (long)count;
        root = sqrt((double)count);
        printf("Number: %d Square: %ld Root: %10.5lf\n",
                count, square, root);
    }
}