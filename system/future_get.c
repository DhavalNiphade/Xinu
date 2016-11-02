/* Future get - future_get.c  */

#include<xinu.h>
#include<future.h>

typedef struct futent future;

syscall future_get(future *f, int *value)
 {

	intmask mask;
	mask=disable();  //Disable the interrupt mask

	f->pid=getpid();
		
if(f->state==FUTURE_EMPTY){			
		f->state=FUTURE_WAITING;
		suspend(f->pid);
	}
		
if(f->state==FUTURE_VALID){
		*value=f->value;
		f->state=FUTURE_EMPTY;
		return OK;
	}

if(f->state==FUTURE_WAITING){
		restore(mask);
		return SYSERR;
	}

restore(mask);
return OK;

}