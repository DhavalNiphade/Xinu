#include <xinu.h>
#include <prodcons.h>
#include <stdio.h>

	sid32 produced;
	sid32 consumed;


void consume(int count)
{

	int32 j=0;
	for(j=0;j<=count;j++)
		{
			wait(produced);

			printf("Consumer : %d", n);	/* Print the consumed value of the global variable */
			printf("\n");

			signal(consumed);
		}
}

