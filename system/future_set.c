/* Future set - future_set.c  */

#include<xinu.h>
#include<future.h>

typedef struct futent future;

syscall future_set(future *f, int *value) {

intmask mask;
mask=disable(); //Disable the interrupt mask

/*if(f->state==FUTURE_EMPTY)	
	{
		f->value=*value;
		f->state=FUTURE_VALID;
		printf("\nPID is %d", f->pid);
		
		resume(f->pid);
		//printf("\n\nThis worked too");
		return OK;
			
	}
	*/

if((f->state==FUTURE_WAITING)||(f->state==FUTURE_EMPTY))	
	{
		//printf("\nEntered through Waiting state");
		
		f->value=*value;
		f->state=FUTURE_VALID;
		//printf("\nSET PID is %d", f->pid);
		
		resume(f->pid);
		//printf("This process resumed\n");
		return OK;		
	}


if(f->state==FUTURE_VALID)	
	{
		restore(mask);
		return SYSERR;
	}
	
restore(mask);
return OK;
}
