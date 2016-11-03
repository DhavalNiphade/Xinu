/* Future set - future_set.c  */

#include<xinu.h>
#include<future.h>
#include<future_queue.h>

typedef struct futent future;

syscall future_set(future *f, int *value) {

intmask mask;
mask=disable(); //Disable the interrupt mask

if(f->flag==FUTURE_SHARED) {

	if(f->state==FUTURE_EMPTY) {

	f->value=*value;
	f->state=FUTURE_VALID;
	restore(mask);
	return OK;

	}

	if(f->state==FUTURE_VALID) {
	
	printf("\nCannot produce new value. Old value has not been consumed yet\n");
	restore(mask);
	return SYSERR;
	
	}

	if(f->state==FUTURE_WAITING) {

	f->value=*value;
	f->state=FUTURE_VALID;

	while (!(empty(f->get_queue))) 
		resume(fdequeue(f->get_queue));

	}

	restore(mask);
	return SYSERR;

}

else if(f->flag==FUTURE_EXCLUSIVE) {

	if(f->state==FUTURE_EMPTY){
		
			f->value=*value;
			f->state=FUTURE_VALID;
			restore(mask);
			return OK;
	 	}


	if((f->state==FUTURE_WAITING)){
		
			f->value=*value;
			f->state=FUTURE_VALID;
			
			resume(f->pid);
			restore(mask);
			return OK;		
		}


	if(f->state==FUTURE_VALID)	{
			restore(mask);
			return SYSERR;
		}

}

else if (f->flag==FUTURE_QUEUE) {

	if(f->state==FUTURE_EMPTY) {
	
	f->value=*value;
	f->state=FUTURE_VALID;
	restore(mask);
	return OK;

	}		

	if(f->state==FUTURE_WAITING) {

		f->value=*value;
		f->state=FUTURE_VALID;

		if (!(empty(f->get_queue))) 
			resume(fdequeue(f->get_queue));

	}

	if(f->state==FUTURE_VALID) {

	pid32 p = getpid();
	fenqueue(f->set_queue, p);
	if(!empty(f->get_queue)) {

		resume(fdequeue(f->get_queue));
		suspend(p);
		restore(mask);

		}
	}

restore(mask);
return OK;
}