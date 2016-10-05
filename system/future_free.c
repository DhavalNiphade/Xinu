/* Future Free - future_free.c  */

#include<xinu.h>
#include<future.h>

typedef struct futent future;

 syscall future_free(future *f)
 {

intmask mask;
mask=disable(); //Disable the interrupt mask

if(f->flag!=FUTURE_EXCLUSIVE||f->state==FUTURE_WAITING)	
	{
		restore(mask);
		return SYSERR;
	}

return freemem(&f, sizeof(f));
	
//restore(mask); 					//Enable the interrupt mask
//return(fut); 						//Return the future

}
