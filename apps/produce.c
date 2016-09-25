#include <xinu.h>
#include <prodcons.h>
#include <stdio.h>

void produce(int count)
{
	sid32 prodcons, consumed;
	
	int32 i;
	for(i=0; i<=count; i++)
	{
		wait(consumed);	/*Check if semaphore count is nonnegative. If yes, return to the caller*/
		n=i; /* Assign counter to Global variable */
		signal(produced);	/*Check to see if the semaphore count is negative. If yes, get process ready */
		printf("Producer : %d", n);	/*Print produced global variable */
		printf("\n");
	}

}



