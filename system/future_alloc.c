/* Future allocation - future_alloc.c  */

#include<xinu.h>
#include<future.h>

typedef struct futent future;

future* future_alloc(int future_flag)
 {

intmask mask;
mask=disable(); //Disable the interrupt mask

future *fu=getmem(sizeof(future));

if (fu!=SYSERR) {

	fu->value=0;
	fu->flag=future_flag;
	fu->state=FUTURE_EMPTY;
	fu->pid=0;
	fu->get_queue=0;
	fu->set_queue=0;
	
	if(fu->flag==FUTURE_SHARED)
		fu->get_queue=init_proc_queue();
	
	if(fu->flag==FUTURE_QUEUE) {
		fu->get_queue=init_proc_queue();
		fu->set_queue=init_proc_queue();
	}

}

restore(mask); 					//Enable the interrupt mask
return fu ; 						//Return the future	

}
