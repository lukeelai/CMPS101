//Luke Lai
//1355154
//luelai
//5/27/15
//CS101
//Allen Van Gelder
//dfsTrace1.h
//header file for dfsTrace1.c


#ifndef C101DFS
#define C101DFS

void dfs(IntList * graph, char ** color, int curr, int* dTime, int* fTime, int* parent, int* finishStk);
//pre-condition: color is intialized to white in the beginnning
//color is grey when visited first time
//post-condition: color becomes black when visited twice

void dfsSweep(IntList * graph, int size, int* dTime, int* fTime, int* parent, int* finishStk);
//pre-condition: color is intialized to white in the beginning
	//time is incremented to 0
	//stack is incremented to 0
//post-condition: intiliazes parent or call dfs

#endif
