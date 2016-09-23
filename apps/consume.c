#include <xinu.h>
#include <prodcons.h>
#include <stdio.h>

void consume(int count)
{
	int32 j;
	for(j=0;j<=count;j++)
		{
			printf("Consumer : %d", n);	/* Print the consumed value of the global variable */
			printf("\n");
		}
}

