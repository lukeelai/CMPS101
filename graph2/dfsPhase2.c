//Luke Lai
//1355154
//luelai
//5/27/15
//CS101
//Allen Van Gelder
//dfsPhase2.c
//Second part of the strongly connected compnent to do the dfs on a transposed graph

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intList.h"
#include "dfsPhase2.h"

int time;
int stackE;
int dStack;

void dfsT(IntList* graph, char ** color, int v, int* dTime, int* fTime, int* parent, int* finishStk, int* dfstRoot){
	color[v] = "gray";

	time++;
	dTime[v] = time;

	IntList ran;	
	ran = graph[v];

	int w;
	
	//for edge vw, if w hasn't been visited, traverse that edge
	while(ran != intNil){
		w = intFirst(ran)-1;
		if(strcmp(color[w], "white") == 0){
			parent[w] = v+1;
			dfsT(graph, color, w, dTime, fTime, parent, finishStk, dfstRoot);
			}
		ran = intRest(ran);
	}
	time++;
	fTime[v] = time;
	color[v] = "black";
	dfstRoot[dStack++] = v+1;
}

void dfsSweepT(IntList* graph, int size, int* dTime, int* fTime, int* parent, int* finishStk, int* dfstRoot){
	//declare and initialize colors to white
	char *color[size];
	int i;
	for(i=0; i<size; i++){
		color[i] = "white";
	}

	time = 0;
	dStack=0;
	stackE = size-1;

	//reads from top of stack instead of in order
	int top = finishStk[stackE]-1; 
	while(stackE >= 0){
		if(strcmp(color[top], "white") == 0){
			parent[top] = -1;
			dfsT(graph, color, top, dTime, fTime, parent, finishStk, dfstRoot);
		}
		stackE--;
		top = finishStk[stackE]-1; 
	}
}
