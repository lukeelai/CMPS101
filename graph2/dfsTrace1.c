//Luke Lai
//1355154
//luelai
//5/27/15
//CS101
//Allen Van Gelder
//dfsTrace1.c
//does a depth first search

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intList.h"
#include "dfsTrace1.h"

int time;
int stackE;

void dfs(IntList* graph, char ** color, int v, int* dTime, int* fTime, int* parent, int* finishStk){
	color[v] = "gray";

	time++;
	dTime[v] = time;

	IntList rem;	
	rem = graph[v];

	int w;
	
	while(rem != intNil){
		w = intFirst(rem)-1;
		if(strcmp(color[w], "white") == 0){
			//Exploratory process for tree edge vw
			parent[w] = v + 1;
			dfs(graph, color, w, dTime, fTime, parent, finishStk);
			//backtrack processing for tree edge vw using vAns (like inorder)
			}
			//Checking(i.e. processing) for nontree edge vw
		rem = intRest(rem);
	}
	//postorder processing of vertex v, including final computation of ans
	time++;
	fTime[v] = time;
	color[v] = "black";
	finishStk[stackE++] = v + 1;
}

void dfsSweep(IntList* graph, int size, int* dTime, int* fTime, int* parent, int* finishStk){
	//declare and initialize colors to white
	char *color[size];
	int i;
	for(i = 0; i < size; i++){
		color[i] = "white";
	}

	time = 0;
	stackE = 0;

	for(i = 0; i < size; i++){
		if(strcmp(color[i], "white") == 0){
			parent[i] = -1;
			dfs(graph, color, i, dTime, fTime, parent, finishStk);
		}
	}
}
