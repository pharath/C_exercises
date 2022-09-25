/* check size of a pointer */

#include<stdio.h>

int main()
{
	char c='A';
	char *ptr=&c;
	printf("The size of the character pointer is %ld bytes.\n",sizeof(ptr));
	return 0;
}
