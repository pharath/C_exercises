//Listing 9.7 Demonstrates passing by reference
// using references!
#include <iostream>

void swap(int &x, int &y);

int main()
{
	int x = 5, y = 10;
	
	printf("Main. Before swap, x: %d, y: %d\n",x,y);
	
	swap(x,y);
	
	printf("Main. After swap, x: %d, y: %d\n",x,y);
	
	return 0;
}

void swap (int &rx, int &ry)
{
	int temp;
	
	printf("Swap. Before swap, rx: %d, ry: %d\n", rx, ry);
	
	temp = rx; // rx ist ein alias für das x in main(); d.h. alles was wir mit rx machen, wird auch auf x angewendet!
	rx = ry;
	ry = temp;
	
	printf("Swap. After swap, rx: %d, ry: %d\n", rx, ry);
	
}
