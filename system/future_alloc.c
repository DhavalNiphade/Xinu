/* Future allocation - future_alloc.c  */

#include<xinu.h>
#include<future.h>

typedef struct futent future;

future* future_alloc(int future_flag)
 {

intmask mask;
mask=disable(); //Disable the interrupt mask

future *f=getmem(sizeof(future));
//printf("\nAddress of fut : %s",*fut);
//printf("\n %d",sizeof(future));

/*if(fut.future_flag!=FUTURE_EXCLUSIVE||fut.future_state==FUTURE_WAITING)	
	{
		restore(mask);
		return SYSERR;
	}
*/


		//fut->*value=; 					Initialize value to entered input
		f->flag=FUTURE_EXCLUSIVE; 			//Initialize in state where there is a one to one relationship between threads calling get & set 
		f->state=FUTURE_EMPTY;				//Initiliaze to Empty state
		//printf("\nFuture generated : %d", f->state);			
										

restore(mask); 					//Enable the interrupt mask
return(f); 						//Return the future	

}
