/* Future get - future_get.c  */

#include<xinu.h>
#include<future.h>

typedef struct futent future;

 syscall future_get(future *f, int *value)
 {

intmask mask;
mask=disable(); //Disable the interrupt mask

//if(f->state==FUTURE_EMPTY)	
	//{
		f->pid=getpid();
		f->state=FUTURE_WAITING;
		printf("\n	This worked!");
		sleep(10000);
		restore(mask);
		return OK;
	//}

if(f->state==FUTURE_WAITING)	
	{
		restore(mask);
		return SYSERR;
	}

}
