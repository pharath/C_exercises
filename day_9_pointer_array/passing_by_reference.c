//adapted from "C++ in 21 days"
//Listing 9.6 Demonstrates passing by reference
//in C gibt es keine references ! Trotzdem sagt man colloquially "pass by reference".
#include <stdio.h>

void swap(int *x, int *y);

int main()
{
	int x = 5, y = 10;
	
	printf("Main. Before swap, x: %d, y: %d\n",x,y);
	swap(&x,&y);
	printf("Main. After swap, x: %d, y: %d\n",x,y);
	return 0;
}

void swap (int *px, int *py)
{
	int temp;
	
	printf("Swap. Before swap, *px: %d, *py: %d\n",*px,*py);
	
	temp = *px;
	*px = *py;
	*py = temp;
	
	printf("Swap. After swap, *px: %d, *py: %d\n",*px,*py);
	
}
