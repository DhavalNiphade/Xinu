#include <xinu.h>
#include <prodcons.h>
#include <stdio.h>

void consume(int count)
{
	sid32 produced;
	sid32 consumed;

	int32 j=0;
	for(j=0;j<=count;j++)
		{
			wait(produced);

			printf("Consumer : %d", n);	/* Print the consumed value of the global variable */
			printf("\n");

			signal(consumed);
		}
}

