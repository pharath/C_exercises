//Listing 9.8 - Returning multiple values from a function

#include <stdio.h>

short Factor(int n, int* pSquared, int* pCubed);

int main()
{
    int number, squared, cubed;
    short error;

    printf("Enter a number (0 - 20): ");
    scanf("%d", &number);

    error = Factor(number, &squared, &cubed);

    if (!error)
    {
        printf("number: %d\n", number);
        printf("square: %d\n", squared);
        printf("cubed: %d\n", cubed);
    }
    else
        printf("Error encountered!!\n");
    return 0;
}

short Factor(int n, int *pSquared, int *pCubed)
{
    short Value = 0;
    if (n > 20)
        Value = 1;
    else
    {
        *pSquared = n*n;
        *pCubed = n*n*n;
        Value = 0;
    }
    return Value;
}
