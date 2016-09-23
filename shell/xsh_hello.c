	/* xsh_hello.c - xsh_hello */
	
	#include <xinu.h>
	#include <string.h>
	#include <stdio.h>
	
	/*------------------------------------------------------------------------
	 * xsh_hello - Obtain and print the user's string input with the message "Hello <string>, Welcome to the world of Xinu!!"
	 *------------------------------------------------------------------------
	 */
	
	shellcmd xsh_hello(int nargs, char *args[])

{
		int32	input_str;			/*  Used to run across input character array	*/
		
		printf ("Hello ");

		if(nargs>1)
		{
			printf("%s", args[1]);
		}

		if (nargs == 2 && strncmp(args[1], "--help", 7) == 0)
		 {
			printf("Usage: %s\n\n", args[0]);
			printf("Description:\n");
			printf("\tDisplays the text entered after hello with a welcome message\n");
			printf("Options (one per invocation):\n");
			printf("\t-f\tdisplays name in UPPER CASE\n");
			printf("\t-d\tdisplays name in LOWER CASE\n");
			printf("\t--help\tdisplay this help and exit\n");
			return 0;
		}

		for (input_str=2;input_str<nargs;input_str++)
		{
			printf(" %s", args [input_str]);
		}

		printf (", Welcome to the world of Xinu !!");
		printf ("\n");

	return 0;
}
