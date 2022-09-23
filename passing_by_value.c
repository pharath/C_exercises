//Listing 9.5 - Demonstrates passing by value
#include <stdio.h>

void swap(int x, int y);

int main()
{
	int x = 5, y = 10;
	
	printf("Main. Before swap, x: %d", x); 
	printf(" y: %d\n", y);
	swap(x,y);
	printf("Main. After swap, x: %d", x);
        printf(" y: %d\n", y);
	return 0;
}

void swap (int x, int y)
{
	int temp;
	
	printf("Swap. Before swap, x: %d", x);
        printf(" y: %d\n", y);
	
	temp = x;
	x = y;
	y = temp;
	
	printf("Swap. After swap, x: %d", x);
        printf(" y: %d\n", y);
}
