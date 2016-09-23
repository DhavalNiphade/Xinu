#include <xinu.h>
#include <prodcons.h>
#include <stdio.h>

void produce(int count)
{
	int32 i;
	for(i=0; i<=count; i++)
	{
		n=i; /* Assign counter to Global variable */
		printf("Producer : %d", n);	/*Print produced global variable */
		printf("\n");
	}

}



