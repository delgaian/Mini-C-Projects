/*Program that converts between Fahrenheit to Celsius or vice versa based on what user would like*/


/* Adapted From "The C Programming Tutor" by Leon A. Wortman and Thomas O. Sidebottom*/

#include <stdio.h>
#define TRUE 1 
#define FALSE 0

/*main function*/
int main() {
    /*takes in whether user's temperature is Fahrenheit or Celsius*/
    int ForC;
    /*Numerical temperature of the user*/
    float userTemp;
    /*Throws away extra characters*/
    int dummy;

    printf("This program converts from Fahrenheit to Celsius or vice versa!\n\n");
    /*Run the program once and continue while user wants to keep doing conversions*/
    do{
       

        printf("Enter F if your temperature is Fahrenheit or C if your temperature is Celsius: ");
        /*Grab input from stdin*/
        ForC = getchar();
        
        /*Give error message while input is invlaid*/
        while (ForC != 'F' && ForC != 'C') {
            printf("Invalid input, please enter 'F' or 'C': \n" );
            ForC = getchar();
            /*break after valid input is given*/
            continue;
        }

        printf("What is your numerical temperature?\n");
        scanf("%f", &userTemp);
        /*Convert to Celsius if user entered that their temperature is 'F'*/
        if(ForC == 'F') {
            
            float celTemp;
            celTemp  = (5.0 / 9.0) * ((float)userTemp - 32.0);
            dummy = getchar();
            printf("Your temperature of %6.2f Fahrenheit is %6.2f Celsius\n", userTemp, celTemp);
        } 
        /*Convert to Fahrenheit if the user's temperature is 'C'*/
        if (ForC == 'C') {
            float fahrTemp = ((float)userTemp * (9.0 / 5.0)) + 32.0;
            dummy = getchar();
            printf("Your temperature of %6.2f Celsius is %6.2f Fahrenheit\n", userTemp, fahrTemp);
        }
        /*function that checks if user wants more conversions*/
    } while (Continue());
     
    return(0);

}


int Continue() {
    int response;
    int dummy;
    printf("Would you like another conversion? (Y/N): ");

    do {
        /*grab response from user*/
        response = getchar();
        response = tolower(response);

        if (response != 'y' && response != 'n') {
            printf("Invalid input, please enter 'Y' or'N': ");
            /*throw away extra character*/

            response = getchar();
        }
    } while( response != 'y' && response != 'n');
    /*throw away extra character before returning*/
    dummy = getchar();
    /*return true or false based on user's input*/
    return((response == 'y') ? TRUE : FALSE);

    
}
