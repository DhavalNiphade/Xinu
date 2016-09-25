/* prodcons.h  */

/* Marker for the top of a process stack (used to help detect overflow)	*/
extern int n;

void produce (int count);
void consume (int count);

extern sid32 produced, consumed;