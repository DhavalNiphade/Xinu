/* Future get - future_get.c  */

#include<xinu.h>
#include<future.h>

typedef struct futent future;

syscall future_get(future *f, int *value)
 {

	intmask mask;
	mask=disable();  //Disable the interrupt mask

	pid2 p = getpid();

/* For EXCLUSIVE MODE */

if(f->flag==FUTURE_EXCLUSIVE) {
		
	if(f->state==FUTURE_EMPTY){
		f->pid=p;			
		f->state=FUTURE_WAITING;
		suspend(f->pid);
	}
		
	if(f->state==FUTURE_VALID){
		*value=f->value;
		f->state=FUTURE_EMPTY;
		restore(mask);
		return future_free(f);
	}

	if(f->state==FUTURE_WAITING){
		restore(mask);
		return SYSERR;
	}
}

/* For SHARED MODE */

if(f->flag==FUTURE_SHARED) {

	if(f->state==FUTURE_EMPTY) {

		fenqueue(f->get_queue, p);
		f->state=FUTURE_WAITING;
		suspend(p);
	}

	if(f>state==FUTURE_VALID) {
	
	*value=f->value;
	
	if(empty(f->get_queue)) {
		f->state=FUTURE_EMPTY
		future_free(f);
		}
	
	restore(mask);
	return OK;
	}
	
	if(f->state==FUTURE_WAITING) {
	
	fenqueue(f->get_queue, p);
	restore(mask);
	suspend(p);
	
	}
		
}

/* For QUEUE MODE  */

if(f->flag==FUTURE_QUEUE) {

	if(f->state==FUTURE_EMPTY) {
		fenqueue(f->get_queue, p);
		f->state=FUTURE_WAITING;
		restore(mask);
		suspend(p);
	}

	if(f->state==FUTURE_VALID) {
		*value=f->value;
		
		if (!empty(f->get_queue))
			f->state=FUTURE_WAITING;
		else
			f->state=FUTURE_EMPTY;

		if(!empty(f->set_queue))
			resume(fdequeue(f->set_queue));

	restore(mask);
	return OK;
	}

	if(f->state==FUTURE_WAITING) {
		fenqueue(f->get_queue, p);
		if(!empty(f->set_queue))
			resume(fdequeue(f->set_queue))
		restore(mask);
		suspend(p);
	}
}
			
	

restore(mask);
return OK;

}