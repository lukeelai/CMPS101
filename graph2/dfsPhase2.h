//Luke Lai
//1355154
//luelai
//5/27/15
//CS101
//Allen Van Gelder
//dfsPhase2.h
//header file for dfsPhase2.c

#ifndef C101DFS2
#define C101DFS2

void dfsT(IntList * graph, char ** color, int curr, int* dTime, int* fTime, int* parent, int* finishStk, int* dfstRoot);

void dfsSweepT(IntList * graph, int size, int* dTime, int* fTime, int* parent, int* finishStk, int* dfstRoot);

#endif
