//Luke Lai
//1355154
//luelai
//5/27/15
//CS101
//Allen Van Gelder
//ssc03.c
//graph abstract data type prints out the text fp, transposes the graph, and then finds the strongly connected compnents

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char * Cstring;

#include "intList.h"
#include "dfsTrace1.h"
#include "dfsPhase2.h"

//global variables
int size;
char line[1000];
//origGraph is array of IntLists to be transposed
//n is the size of origGraph
IntList* transposeGraph(IntList* origGraph, int n){
   int i;
   int s = 0;
   IntList curr;

   //find length of graph2 by finding max element of origGraph
   for(i = 0; i < n; i++){
      curr = origGraph[i];
      while(curr != intNil){
         if(intFirst(curr) > s)
            s = intFirst(curr);
            curr = intRest(curr);
      }
   }

   //sets new size equal to the max element of the old array
   if(s > size)
      size = s;

   //make and initialize graph2
   IntList* graph2 = calloc(size , sizeof (IntList));
   for(i = 0; i < n; i++){
      graph2[i] = intNil;
   }
   
   //read origGraph and transpose to graph2
   for(i = 0; i < n; i++){
      curr = origGraph[i];
      while(curr != intNil){
         graph2[intFirst(curr)-1] = intCons(i + 1, graph2[intFirst(curr) - 1]);
         curr = intRest(curr);
      }
   }return graph2;
}

int main(int argc, char* argv[]){
   FILE *fp;

   fp = fopen(argv[1], "r");           //reads file
   if(!fp){                //if no file
      perror("No file specified");        //print error
      return -1;
   }
   
   int size = atoi(fgets(line, 1000, fp));         //get the size of the array
   printf("Array Size = %d \n", size);       //print out first line aka size of array

   //struct IntList * list = NULL;
   IntList* array = calloc(size, sizeof(IntList));       //allocate space for array
   
   char * stuff;
   int m;
   int n;
   int ls;
   int j;
   int num = 0;
   //array declaration start
      int dTime1[size];
      int fTime1[size];
      int parent1[size];
      int finishStk1[size];
      //array declaration end
   
   //initialize to null
   for(j = 0; j <= size; j++){
      array[j] = intNil;
   }

   while(fgets(line, 1000, fp) != NULL){        //while there is a line to read 
      stuff = strtok(line, " \t ");       //stuff
      ls = 0;                 //line stuff
      while(stuff != NULL){            //keep goings
         ls++;             //next part on line
         if(ls == 1){            //1st number
            m = atoi(stuff);
         } 
         if(ls == 2){            //2nd number
            n = atoi(stuff);
            if(m >= 0 && m <= size){
                     array[m-1] = intCons(n, array[m-1]);
                     num++;
                  }else printf("No edge for %d, %d\n", m, n);
         }
         stuff = strtok(NULL, " ,.-");    //stops the loop if nothing else is there
      }  
   }
   
int i;   
dfsSweep(array, size, dTime1, fTime1, parent1, finishStk1);
   printf("Original Graph\n");
   //print times and parent for all edges
   for(i = 0; i < size; i++){
      printf("Discover Time [%d]: %d\t", i+1, dTime1[i]);
      printf("Finish Time [%d]: %d\t", i+1, fTime1[i]);
      printf("Parent [%d]: %d \n", i+1, parent1[i]);
   }

   //print the order edges were visited
   printf("Edges:  ");
   for(i = 0; i < size; i++){
      printf("%d  ", finishStk1[i]);
   }
   printf("\n");

   //transpose the graph
   IntList* transGraph = transposeGraph(array, size);

   //print transposed graph
   printf("\nTransposed Graph:\n");

   //array declaration
   int dTime2[size];
   int fTime2[size];
   int parent2[size];
   int dfstRoot2[size];

   dfsSweepT(transGraph, size, dTime2, fTime2, parent2, finishStk1, dfstRoot2);

   //print times and parent for all edges
   for(i = 0; i < size; i++){
      printf("Discover Time [%d]: %d\t", i+1, dTime2[i]);
      printf("Finish Time [%d]: %d\t", i+1, fTime2[i]);
      printf("Parent [%d]: %d \n", i+1, parent2[i]);
   }

   //print the order edges were visited
   printf("Edges:  ");
   for(i = 0; i < size; i++){
      printf("%d  ", dfstRoot2[i]);
   }
   printf("\n");

   //close file and exit  
   fclose(fp);
   return 0;
}
