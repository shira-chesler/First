CC = gcc
CFLAGS = -g -Wall

loops : libclassloops

recursives : libclassrec

loopd : libclassrec.so

libclassloops.a : basicClassification.o advancedClassificationLoop.o
	ar -rc libclassloops.a basicClassification.o advancedClassificationLoop.o

libclassrec.a : basicClassification.o advancedClassificationRecursion.o
	ar -rc libclassrec.a basicClassification.o advancedClassificationRecursion.os

libclassrec.so : basicClassification.c advancedClassificationRecursion.c
	$(CC) $(CFLAGS) -fPIC -c basicClassification.c advancedClassificationRecursion.c
	$(CC) $(CFLAGS) -shared basicClassification.o advancedClassificationRecursion.o -o libclassrec.so
	export LD_LIBRARY_PATH = .:$LD_LIBRARY_PATH

libclassloops.so : basicClassification.c advancedClassificationLoop.o
	$(CC) $(CFLAGS) -fPIC -c basicClassification.c advancedClassificationLoop.c
	$(CC) $(CFLAGS) -shared basicClassification.o advancedClassificationLoop.o -o libclassloops.so
	export LD_LIBRARY_PATH = .:$LD_LIBRARY_PATH

mains : main.o libclassrec.a
	$(CC) main.o -lclassrec -L. -o mains

maindloop : main.c libclassloops.so
	$(CC) $(CFLAGS) -c main.c -L. -lclassloops -o maindloop
