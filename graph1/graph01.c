 //Luke Lai
//1355154
//luelai
//6/3/15
//CS101
//Allen Van Gelder
//sgraph04.c
//graph abstract data type prints out the text file and finds the minimum spanning tree

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "edgeList.h"
#include "minPQ.h"

//typedef char * Cstring;

int size;

char line[1000]; /* A generous overestimate for any one line */

/*See if a better connection is found to any vertex in the 
list adjInfoOfV, and decreaseKey is so. 
For a new connection, insert the vertex*/


void updateFringe(MinPQ pq, EdgeList adj, int v){
   EdgeList rem;
   rem = adj;

   while(rem != edgeNil){
      EdgeInfo wInfo = edgeFirst(rem);
      int w = wInfo.to;
      double newWgt = wInfo.wgt;
      if(getStatus(pq, w) == 'u'){
         insertPQ(pq, w, newWgt, v);
      }else if(getStatus(pq, w) == 'f' && newWgt < getPriority(pq,w)){
         decreaseKey(pq, w, newWgt, v);
      }rem = edgeRest(rem);
   }return;
}


void primMst(EdgeList * adj, int n, int s, int * status, int * parent, double * fringeWgt){
   MinPQ pq = createPQ(n, status, fringeWgt, parent);

   insertPQ(pq, s, 0, -1);
   while(isEmptyPQ(pq) != 0){
      int v = getMin(pq);
      delMin(pq);
      updateFringe(pq, adj[v], v);
   }return;
}

void updateFringe2(MinPQ pq, EdgeList adj, int v){
   EdgeList rem;
   rem = adj;

   while(rem != edgeNil){
      EdgeInfo wInfo = edgeFirst(rem);
      int w = wInfo.to;
      double newWgt = wInfo.wgt + getPriority(pq,v);
      if(getStatus(pq, w) == 'u'){
         insertPQ(pq, w, newWgt, v);
      }else if(getStatus(pq, w) == 'f' && newWgt < getPriority(pq,w)){
         decreaseKey(pq, w, newWgt, v);
      }rem = edgeRest(rem);
   }return;
}

void dijk(EdgeList * adj, int n, int s, int * status, int * parent, double * fringeWgt){
   MinPQ pq = createPQ(n, status, fringeWgt, parent);

   insertPQ(pq, s, 0, -1);
   while(isEmptyPQ(pq) != 0){
      int v = getMin(pq);
      delMin(pq);
      updateFringe2(pq, adj[v], v);
   }return;
}


void greedyTree(int task, EdgeList * array, int size, int startingV, int * status, int * parent, double * fringeWgt){
   int i;
   if(task == 1){
      printf("Dijkstra's\n");
      dijk(array, size, startingV, status, parent, fringeWgt);
      for(i = 1; i<=size; i++){
            printf("Vertice: %d, Status: %c, Weight: %lf, Parent: %d\n", i, status[i], fringeWgt[i], parent[i]);
      }
   }else if(task == 2){
      printf("Prim's\n");
      primMst(array, size, startingV, status, parent, fringeWgt);
      //print all EdgeLists and their location in the array 
      for(i = 1; i<=size; i++){
            printf("Vertice: %d, Status: %c, Weight: %lf, Parent: %d\n", i, status[i], fringeWgt[i], parent[i]);
      }
   }else printf("Flag not recognized\n");
}


int main (int argc, char *argv[]){
   //open file
   FILE *file;
   file = fopen(argv[3], "r");
   if(!file) return 1;

 //command line option for Dijkstra's S-P Alg (boolean)
   int task = 0;
   if(strcmp(argv[1], "-D") == 0)
      task = 1;
   else if(strcmp(argv[1], "-P") == 0)
      task = 2;
   
   //starting vertex
   int startingV = atoi(argv[2]);


   //variable for current line
   char line[200];

   //first line is size
   size = atoi(fgets(line, 200, file));
   printf("Number of Vertices: %d\n", size);

   //create array and initialize
   EdgeList* array = calloc(size+1, sizeof(EdgeList));
   int c;
   for(c=0; c<=size; c++){
      array[c]=edgeNil;
   }

   int* status = calloc(size + 1, sizeof(MinPQ));
   int parent[size+1];
   double fringeWgt[size+1];



   //all other lines add to array
   char * currPart;
   int part1;
   int part2;
   double part3;
   int total =0;
   //scans file until lines are empty
   while (fgets(line, 200, file)!= NULL){
      //currPart is the separated digits of the line
      currPart = strtok(line, " ");
      //lineIndex decides whether the number is used or not
      int lineIndex = 0;
      //scans until line is empty
      while(currPart!=NULL){
         lineIndex++;
         //first number on the line
         if(lineIndex == 1){
            part1 = atoi(currPart);
         }
         //second number on the line
         if(lineIndex == 2){
            part2 = atoi(currPart);
            if(part1 < 0 && part1 >= size)
               printf("Edge not in range %d, %d", part1, part2);
         }
       if(lineIndex == 3){
        part3 = atof(currPart);
        EdgeInfo newEdge;
             newEdge.to = part2;
        newEdge.wgt = part3;
        array[part1]=edgeCons(newEdge, array[part1]);
        total++;
       }
         //stops loop
         currPart=strtok(NULL, " ,-");
      }
   }

   /*
   //print total number of elements added
   printf("total elements added: %d\n", total);
   //print all EdgeLists and their location in the array 
   int i;
   EdgeList currNode;
   for(i = 1; i<=size; i++){
      printf("%d", i);
      currNode=array[i];
      while(currNode!=edgeNil){
         printf("\tTo: %d, Weight: %f", edgeFirst(currNode).to, edgeFirst(currNode).wgt);
         currNode=edgeRest(currNode);
         if(currNode != edgeNil) printf("\n");
      }printf("\n");
   }
   */
   greedyTree(task, array, size, startingV, status, parent, fringeWgt);
   //close file and exit  
   fclose(file);
   return 0;
}
