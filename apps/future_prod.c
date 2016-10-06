#include <xinu.h>
#include <prodcons.h>
#include <stdio.h>
#include <future.h>

uint future_prod(future *fut) {
  int i, j;
  j = (int)fut;
  for (i=0; i<5; i++)
	{
		j += i;
		future_set(fut, &j);
	}
	
  return OK;
}



