/* https://www.programiz.com/c-programming/c-structures-pointers */

#include <stdio.h>
struct person
{
   int age;
   float weight;
};

int main()
{
    struct person *personPtr, person1;
    personPtr = &person1;   

    printf("Enter age: ");
    scanf("%d", &personPtr->age);   // operator precedence: "->" geht vor "&"; scanf syntax: scanf("%d", &some_signed_int)

    printf("Enter weight: ");
    scanf("%f", &personPtr->weight);

    printf("Displaying:\n");
    printf("Age: %d\n", personPtr->age);
    printf("weight: %f\n", personPtr->weight);

    return 0;
}
