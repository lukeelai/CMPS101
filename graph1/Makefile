# Luke Lai
# 1355154
# luelai
# 6/3/15
# CS101
# Allen Van Gelder
# Makefile
# Makefile for pa04

# See Cmake/Makefile for a complete commented sample Makefile,
# illustrating separate compilation and dependencies.

# Running "make" can generate many error messages.  Do
#	make intList.o >& make.log
# to compile intList.c and cause the errors to go into the file make.log.
# When "make" finishes you can read the file with "view", "more", or "less".
#
# Many later error messages can be meaningless because they were caused
# by an earlier error.  Always try to correct errors in order.
#
# Do 
#       make graph01 >& make.log
# to create the executable file graph01.
#
# ===================================================================

CC     = gcc
CFLAGS = -g -Wall -O0
OUTPUT = graph04 test.txt

graph04:	graph04.o  edgeList.o  minPQ.o
	${CC}  -o  graph04  graph04.o edgeList.o minPQ.o

edgeList.o:	edgeList.c  edgeList.h
	${CC}  -c  ${CFLAGS}  edgeList.c

minPQ.o: minPQ.c minPQ.h
	${CC}  -c  ${CFLAGS} minPQ.c

graph04.o:	graph04.c  edgeList.h 
	${CC}  -c  ${CFLAGS}  graph04.c

test: ${OUTPUT}
	./${OUTPUT}

clean: 
	rm -f *.o

spotless: clean
	rm -f ${OUTPUT}

.PHONY: clean spotles test
