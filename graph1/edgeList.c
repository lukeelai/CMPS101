//Luke Lai
//1355154
//luelai
//6/3/15
//CS101
//Allen Van Gelder
//EdgeList.c
//defines an edge list

#include <stdio.h>
#include <stdlib.h>
#include "edgeList.h"

struct EdgeListNode{
  EdgeInfo element;
  EdgeList next;
};

const EdgeList edgeNil = NULL;

EdgeInfo edgeFirst(EdgeList oldL){ 
  return (oldL->element);
}

EdgeList edgeRest(EdgeList oldL){ 
  return (oldL->next); 
}

 // the real constructor, but we want cons() for interface.
EdgeList edgeCons(EdgeInfo newE, EdgeList oldL){
  EdgeList newL = calloc(1, sizeof(struct EdgeListNode));
  newL->element = newE;
  newL->next = oldL;
  return newL;
}
