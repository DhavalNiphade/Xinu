#include <xinu.h>
#include <prodcons.h>
#include <stdio.h>
#include <future.h>

	
uint future_cons(future *fut) {

  int i, status;
  for(int j=0;j<5;j++){
  status = future_get(fut, &i);

  if (status < 1) {
    printf("\nfuture_get failed\n");
    return -1;
  }

  printf("\nit produced %d\n", i);
  
  }
  
  return OK;
 
}

