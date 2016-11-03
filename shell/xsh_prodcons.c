/* xsh_prodcons - Produce integer values from one function and print corresponding values from another */

#include <xinu.h>
#include <string.h>
#include <stdio.h>
#include <prodcons.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include<future.h>

uint future_cons(future*);
uint future_prod(future*);


/* Declared variables and prototypes from the include function */

int n;	/* Define global variable */

sid32 produced, consumed;

shellcmd xsh_prodcons(int nargs, char *args[])
 {

produced=semcreate(0);
consumed=semcreate(1);

int count=2000;								/* Initialize count */
		
	 if (nargs > 2)
	 {
		fprintf(stderr, "%s: too many arguments\n", args[0]);
		fprintf(stderr, "Try '%s --help' for more information\n", args[0]);
		return 1;
	}

	/* Output info for '--help' argument */

	if (nargs == 2)
	{
	  if(strncmp(args[1], "--help", 7) == 0)
		{
			printf("Usage: %s\n\n", args[0]);
			printf("Description:\n");
			printf("\tDemonstrates concurrent producer and consumer function operation\n");
			printf("\t--help\tdisplay this help and exit\n");
			return 1;
		}

	if(strncmp(args[1], "-f", 3) == 0)
		{
			printf("\nCommand initiated Prodcons simulation with Futures\n");
			future *f1, *f2, *f3;
 
  			f1 = future_alloc(FUTURE_EXCLUSIVE);
  			f2 = future_alloc(FUTURE_EXCLUSIVE);
 			f3 = future_alloc(FUTURE_EXCLUSIVE);
 
 			resume( create(future_cons, 1024, 20, "fcons1", 1, f1) );
 			resume( create(future_prod, 1024, 20, "fprod1", 1, f1) );
  			resume( create(future_cons, 1024, 20, "fcons2", 1, f2) );
 			resume( create(future_prod, 1024, 20, "fprod2", 1, f2) );
 			resume( create(future_cons, 1024, 20, "fcons3", 1, f3) );
  			resume( create(future_prod, 1024, 20, "fprod3", 1, f3) );
			
			return 0;
		}

	if(strncmp(args[1],"-ff",4)==0)
	{
		printf("\nCommand initiate prodcons simulation with Futures Version 2\n");
		future *f_exclusive, *f_shared, *f_queue;
 
 		 f_exclusive = future_alloc(FUTURE_EXCLUSIVE);
		 f_shared = future_alloc(FUTURE_SHARED);
		 f_queue = future_alloc(FUTURE_QUEUE);

		// Test FUTURE_EXCLUSIVE
  		resume( create(future_cons, 1024, 20, "fcons1", 1, f_exclusive) );
		resume( create(future_prod, 1024, 20, "fprod1", 1, f_exclusive) );

		// Test FUTURE_SHARED
		resume( create(future_cons, 1024, 20, "fcons2", 1, f_shared) );
		resume( create(future_cons, 1024, 20, "fcons3", 1, f_shared) );
		resume( create(future_cons, 1024, 20, "fcons4", 1, f_shared) ); 
		resume( create(future_cons, 1024, 20, "fcons5", 1, f_shared) );
		resume( create(future_prod, 1024, 20, "fprod2", 1, f_shared) );

		// Test FUTURE_QUEUE
		resume( create(future_cons, 1024, 20, "fcons6", 1, f_queue) );
		resume( create(future_cons, 1024, 20, "fcons7", 1, f_queue) );
		resume( create(future_cons, 1024, 20, "fcons7", 1, f_queue) );
		resume( create(future_cons, 1024, 20, "fcons7", 1, f_queue) );
		resume( create(future_prod, 1024, 20, "fprod3", 1, f_queue) );
		resume( create(future_prod, 1024, 20, "fprod4", 1, f_queue) )
		resume( create(future_prod, 1024, 20, "fprod5", 1, f_queue) );
		 resume( create(future_prod, 1024, 20, "fprod6", 1, f_queue) );

		return 0;
	}
	
	if(isalpha(args[1]))
		printf("Please enter numeric values\n");
					
	else
		{	
			count=atoi(args[1]); 
		}
	}
	
	resume( create(produce,1024,20,"produce",1,count ));
	resume( create(consume,1024,20,"consume",1,count));

	
return 0;

}

