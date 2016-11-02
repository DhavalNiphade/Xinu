/* Future set - future_set.c  */

#include<xinu.h>
#include<future.h>
#include<future_queue.h>

typedef struct futent future;

syscall future_set(future *f, int *value) {

intmask mask;
mask=disable(); //Disable the interrupt mask

if(f->flag==FUTURE_SHARED) {

	restore(mask);
	return SYSERR;

}


else if(f->flag==FUTURE_EXCLUSIVE) {

	f->flag=FUTURE_SHARED;

		if(f->state==FUTURE_EMPTY){
		
			f->value=*value;
			f->state=FUTURE_VALID;
		
			return OK;
	 	}


		if((f->state==FUTURE_WAITING)){
		
			f->value=*value;
			f->state=FUTURE_VALID;
			
			for(int i=0;i<get-queue->size;i++)
			{
			pid32 process_id = f->pid;
			resume(process_id);
			future_free();
			}
			return OK;		
		}


		if(f->state==FUTURE_VALID)	{
			restore(mask);
			return SYSERR;
		}

}


	
restore(mask);
return OK;
}