// Usage of rand() function

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
   int i, n;
   time_t t;
   
   n = 5;
   
   /* Intializes random number generator */
   srand((unsigned) time(&t));  // seeds the random number generator used by the function rand.
                                // prototype: void srand(unsigned int seed);
                                //
                                // "(unsigned)" is a typecast; time() returns UNIX time as time_t (which is a typedef for long)
                                //
                                // difference "prototype" and "declaration":
                                // All prototypes are declarations, but not all declarations are prototypes.
                                // A function prototype is a declaration of a function that declares the types of its parameters.

   /* Print 5 random numbers from 0 to 49 */
   for( i = 0 ; i < n ; i++ ) {
      printf("%d\n", rand() % 50);
   }
   
   return(0);
}