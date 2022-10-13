/* Using malloc() to determine free memory.*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

/* Definition of a structure that is
1024 bytes (1 kilobyte) in size.) */

struct kilo {
	struct kilo *next;	// for a 64 bit computer the pointer size is 8 bytes 
	char dummy[1016];
};

int FreeMem(void);

// int main( void )
int main( int argc, char *argv[] )
{
	/* phth start: */
	/* explanation: see setrlimit.c */
	struct rlimit lim = {1, 1};

	if (argc > 1 && argv[1][0] == '-' && argv[1][1]=='l') {
			printf("limiting stack size\n");
			if (setrlimit(RLIMIT_STACK, &lim) == -1) {
					printf("rlimit failed\n");
					return 1;
			}
			printf("limiting heap size\n");
			if (setrlimit(RLIMIT_DATA, &lim) == -1) {
					printf("rlimit failed\n");
					return 1;
			}
	}
	/* phth end */
		
	printf("You have %d kilobytes free.\n", FreeMem());
	return 0;
}

int FreeMem(void)
{
	/*Returns the number of kilobytes (1024 bytes)
	of free memory. */
	
	long counter;
	struct kilo *head, *current, *nextone;
	
	current = head = (struct kilo*) malloc(sizeof(struct kilo));
	
	if (head == NULL)
		return 0; /*No memory available.*/
	
	counter = 0;
	do
	{
		counter++;
		current->next = (struct kilo*) malloc(sizeof(struct kilo));
		current = current->next;
		printf("\r%ld", counter);	// \r is a carriage return character: printing a \r allows to override the current line of the terminal emulator
	// } while (counter != 300000);	// because original code is for DOS, but for Win10 and UNIX it does not work (takes a very long time to exhaust available memory, including "virtual memory")
	} while (current != NULL);	// technically, this is not a linked list until malloc returns NULL ! Before malloc returns NULL the last struct in the list always has an uninitialized "next" member pointer (not a NULL pointer!)!
	printf("\n");
	
	/* Now counter holds the number of type kilo
	structures we were able to allocate. We
	must free them all before returning. */
	
	current = head;
	counter = 0;	// add counter to see, if following loop is running
	do
	{
		counter++;
		nextone = current->next;
		free(current);
		current = nextone;
		printf("\r%ld", counter);
	} while (nextone != NULL);
	printf("\n");
	
	return counter;
}
