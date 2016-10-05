/* Future set - future_set.c  */

#include<xinu.h>
#include<future.h>

typedef struct futent future;

syscall future_set(future *f, int *value) {

intmask mask;
mask=disable(); //Disable the interrupt mask

//if(f->state==FUTURE_WAITING)	
	//{
		f->value=*value;
		f->state=FUTURE_VALID;
		wakeup();
		restore(mask);
		return OK;
	//}

/*if(f->state==FUTURE_VALID)	
	{
		restore(mask);
		return SYSERR;
	}
*/
}
