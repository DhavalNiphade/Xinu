/* Future get - future_get.c  */

#include<xinu.h>
#include<future.h>

typedef struct futent future;

syscall future_get(future *f, int *value)
 {

	intmask mask;
	mask=disable();  //Disable the interrupt mask

	f->pid=getpid();
	//printf("\nGet PID is %d", f->pid);
	
if(f->state==FUTURE_EMPTY)	
	{			
		f->state=FUTURE_WAITING;
		suspend(f->pid);
		return OK;
		//printf("\nThis process was suspended");
	}
		
	/*f->state=FUTURE_EMPTY;
	f->value=*value;
	printf("\nReached here");
	*/
	
if(f->state=FUTURE_VALID)
	{
		*value=f->value;
		f->state=FUTURE_WAITING;
		suspend(f->pid);
		//printf("Reached here");	
		return OK;
	}

if(f->state==FUTURE_WAITING)	
	{
		restore(mask);
		return SYSERR;
	}


restore(mask);
return OK;

}
