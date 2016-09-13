//Luke Lai
//1355154
//luelai
//6/3/15
//CS101
//Allen Van Gelder
//minPQ.c
//defines a minPQ
#include <stdio.h>
#include <stdlib.h>
#include "minPQ.h"

//Instance fields
int numVertices;
int numPQ;
int minVertex;
double oo;
int* status;
int* parent;
double* fringeWgt;


//used to check if pq is empty
int isEmptyPQ(MinPQ pq){
	if(numPQ == 0)return 0;
	return 1;
}


int getStatus(MinPQ pq, int v){
	return status[v];
}

int getParent(MinPQ pq, int v){
	return parent[v];
}

double getPriority(MinPQ pq, int v){
	return fringeWgt[v];
}

/*record newPar, newW as parent, priority of v 
and make status[v] = fringe*/

//delete fringe vertex with min wgt from pq
void delMin(MinPQ pq){
	int oldMin = getMin(pq);

	status[oldMin] = 't';
	minVertex = -1;
	numPQ--;
	return;
}

void insertPQ(MinPQ pq, int v, double priority, int par){
	parent[v] = par;
	fringeWgt[v] = priority;
	status[v] = 'f';
	minVertex = -1;
	numPQ++;
	return;
}

//record newPar, newW as parent, prioirty of v
void decreaseKey(MinPQ pq, int v, double priority, int par){
	parent[v] = par;
	fringeWgt[v] = priority;
	minVertex = -1;
	return;
}

//The subroutine does most of the work
void findMin(MinPQ pq){
	int v;
	double minWgt;

	minWgt = oo;
	for(v = 1; v <= numVertices; v++){
		if(status[v] == 'f'){
			if(fringeWgt[v] < minWgt){
				minVertex = v;
				minWgt = fringeWgt[v];
			}
		}
	}
	return;
}

//return fringe vertex with min wgt
//return -1 if no fringe vertex remains

int getMin(MinPQ pq){
	if(minVertex == -1){
		findMin(pq);
	}return minVertex;
}


//Construct pq on n vertices, all unseen
MinPQ createPQ(int n, int stat[], double prior[], int par[]){
	MinPQ pq = calloc(1, sizeof(MinPQ));
	parent = par;
	fringeWgt = prior;
	status = stat;

	oo = 1.0/0.0;

	//Intilialize status[1] to status[n] to unseen
	int i;
	for(i = 1; i <= n; i++){
		status[i] = 'u';
		parent[i] = -1;
		fringeWgt[i] = oo;
	}

	numVertices = n;
	numPQ = 0;
	minVertex = -1;
	return pq;
}
