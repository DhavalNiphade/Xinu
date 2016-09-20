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

		for (input_str=2;input_str<nargs;input_str++)
		{
			printf(" %s", args [input_str]);
		}

		printf (", Welcome to the world of Xinu !!");
		printf ("\n");

	return 0;
}
