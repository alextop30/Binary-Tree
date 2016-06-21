CC = g++
CFLAGS = -Wall -g -std=c++11

all: bintree

bintree.o: binTree.h includes.h Node.h binTree.cc
	${CC} ${CFLAGS} -c binTree.cc

bintree: bintree.o
	${CC} ${CFLAGS} binTree.o -o binary_tree

clean:
	rm -rf *.o
	rm -rf binary_tree
