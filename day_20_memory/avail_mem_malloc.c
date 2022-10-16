/* Using malloc() to determine free memory.*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

/* Definition of a structure that is
1024 bytes (1 kilobyte) in size.) */

struct kilo {
	struct kilo *next;	// for a 64 bit computer the pointer size is 8 bytes 
	char dummy[1016];
	// char dummy[992];
};

int FreeMem(void);
int LimitMem( int _argc, char *_argv[] );

int main( int argc, char *argv[] )
{
	if (LimitMem( argc, argv ) != 0)
	{
		printf("LimitMem() failed.\n");
		return 1;
	}
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

/* phth start: */
int LimitMem( int _argc, char *_argv[] )
{
	/**
	 * @brief explanation: see setrlimit.c
	 * 
	 */
	
	struct rlimit lim = {3 * 1024 * 1024, RLIM_INFINITY};
	// /* alternatively, using the rlim_cur element of the rlimit structure lim: */
	// struct rlimit lim;
	// lim.rlim_cur = 3 * 1000 * 1000;
	// lim.rlim_max = RLIM_INFINITY;
	
	struct rlimit old_lim, new_lim;

	if (_argc > 1 && _argv[1][0] == '-' && _argv[1][1]=='l') 
	{
		printf("limiting data segment size\n");
		
		getrlimit(RLIMIT_DATA, &old_lim);
		printf("old_lim (hard): %ld Bytes\n", old_lim.rlim_max);
		printf("old_lim (soft): %ld Bytes\n", old_lim.rlim_cur);
		
		if (setrlimit(RLIMIT_DATA, &lim) == -1) 
		{
			printf("rlimit failed\n");
			return 1;
		}
		
		getrlimit(RLIMIT_DATA, &new_lim);
		printf("new_lim (hard): %ld Bytes\n", new_lim.rlim_max);
		printf("new_lim (soft): %ld Bytes\n", new_lim.rlim_cur);
	}

	return 0;
}
/* phth end */
