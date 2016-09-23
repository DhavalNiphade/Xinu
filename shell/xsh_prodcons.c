/* xsh_prodcons - Produce integer values from one function and print corresponding values from another */

#include <xinu.h>
#include <string.h>
#include <stdio.h>
#include <prodcons.h>
#include <ctype.h>
#include <stdlib.h>


/* Declared variables and prototypes from the include function */

int n=0;	/* Define global variable */

shellcmd xsh_prodcons(int nargs, char *args[])
 {
	/* Check input argument count */

	
	if (nargs > 2)
	 {
		fprintf(stderr, "%s: too many arguments\n", args[0]);
		fprintf(stderr, "Try '%s --help' for more information\n", args[0]);
		return 1;
	}

	/* Output info for '--help' argument */

	if (nargs == 2 && strncmp(args[1], "--help", 7) == 0)
	 {
		printf("Usage: %s\n\n", args[0]);
		printf("Description:\n");
		printf("\tDemonstrates concurrent producer and consumer function operation\n");
		printf("\t--help\tdisplay this help and exit\n");
		return 0;
	}

	int count=2000;	/* Initialize global variable */

	count=atoi(args[1]);

	resume( create(produce,1024,20,"produce",1,count));
	resume( create(consume,1024,20,"consume",1,count));
	return (0);

}
