//Luke Lai
//1355154
//luelai
//5/6/15
//CS101
//Allen Van Gelder
//intList.h
//header file for intList.c


/* intList.h
 * (what is the purpose of this file?)
 */
#ifndef C101IntList
#define C101IntList
/* Multiple typedefs for the same type are an error in C. */

typedef struct IntListNode * IntList;

/** intNil denotes the empty IntList */
extern const IntList intNil;

/* Access functions
 * (what are the preconditions?)
 * a precondition is a condition, that if not met, the algoritm isn't required to provide the correct result.
 */

/** first
 */
int intFirst(IntList oldList);

/** rest
 */
IntList intRest(IntList oldList);

/* Constructors
 * (what are the preconditions and postconditions?)
 * The precondition a true statement that you make before running the progam
 * The postcondition something that the code will return after running
 */

/** cons
 */

IntList intCons(int newElement, IntList oldList);

IntList* transposeGraph(IntList* origGraph, int n);

int hasCycle(IntList* origGraph, int n);

int hasCycleLen(IntList* origGraph, int n, int sofar, int v);

#endif
