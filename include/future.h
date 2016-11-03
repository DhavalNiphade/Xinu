#ifndef _FUTURE_H_
#define _FUTURE_H_

#include<future_queue.h>

/* define states */
#define FUTURE_EMPTY	  0
#define FUTURE_WAITING 	  1         
#define FUTURE_VALID 	  2

/* modes of operation for future*/
#define FUTURE_EXCLUSIVE  1
#define FUTURE_SHARED     2	    
#define FUTURE_QUEUE      3 

typedef struct proc_queue{
  pid32 pid;
  struct proc_queue *next;
}proc_queue;

proc_queue* init_proc_queue();
int fisempty(proc_queue *head);
fenqueue (proc_queue *head, pid32 pid);
pid32 fdequeue(proc_queue *head);

typedef struct futent
{
   int *value; //Pointer of value to be held in future	
   int flag;	//Defines mode of operation for the future	
   int state;  //Defines which state the future is in
   pid32 pid; //Process ID for the concerned process waiting on the future
   proc_queue set_queue;	
   proc_queue get_queue;
} future;

/* Interface for system call */
future* future_alloc(int future_flags);
syscall future_free(future*);
syscall future_get(future*, int*);
syscall future_set(future*, int*);

uint future_cons(future *fut);
uint future_prod(future *fut);
 
#endif /* _FUTURE_H_ */
