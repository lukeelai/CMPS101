//Luke Lai
//1355154
//luelai
//5/6/15
//CS101
//Allen Van Gelder
//intList.c
//defines an intlist

#include <stdio.h>
#include <stdlib.h>
#include "intList.h"

struct IntListNode{
	int element;
	IntList next;
};

const IntList intNil = NULL;

int intFirst(IntList aList){ 
	return aList->element; 
}

IntList intRest(IntList aList){ 
	return aList->next; 
}

 // the real constructor, but we want cons() for interface.
IntList intCons(int newElement, IntList oldList){
	IntList newList = calloc(1, sizeof(struct IntListNode));
	newList->element = newElement;
	newList->next = oldList;
	return newList;
}

/*
public
 String toString()
  { return "[" + toStringR("", this); }
 static
 String toStringR(String prefix, IntList L)
  {
  String s;
  if ( L == nil )
   s = "]";
  else
   s = prefix + first(L) + toStringR(", ", rest(L));
  return s;
  }
 }*/
