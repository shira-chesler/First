CC = gcc
CFLAGS = -g -Wall

all : recursived loopd loops recursives mains maindloop maindrec 

loops : libclassloops.a

recursives : libclassrec.a

recursived : libclassrec.so

loopd : libclassloops.so

libclassloops.a : basicClassification.o advancedClassificationLoop.o
	ar -rc libclassloops.a basicClassification.o advancedClassificationLoop.o

libclassrec.a : basicClassification.o advancedClassificationRecursion.o
	ar -rc libclassrec.a basicClassification.o advancedClassificationRecursion.o

libclassrec.so : basicClassification.c advancedClassificationRecursion.c
	$(CC) $(CFLAGS) -fPIC -c basicClassification.c advancedClassificationRecursion.c
	$(CC) $(CFLAGS) -shared basicClassification.o advancedClassificationRecursion.o -o libclassrec.so
	export LD_LIBRARY_PATH=.:$$LD_LIBRARY_PATH

libclassloops.so : basicClassification.c advancedClassificationLoop.c
	$(CC) $(CFLAGS) -fPIC -c basicClassification.c advancedClassificationLoop.c
	$(CC) $(CFLAGS) -shared basicClassification.o advancedClassificationLoop.o -o libclassloops.so
	export LD_LIBRARY_PATH=.:$$LD_LIBRARY_PATH

mains : main.o libclassrec.a
	$(CC) $(CFLAGS) main.o ./libclassrec.a -L. -o mains

maindloop : main.o libclassloops.so
	$(CC) $(CFLAGS) main.o -L. ./libclassloops.so -o maindloop

maindrec: main.o libclassrec.so
	$(CC) $(CFLAGS) main.o -L. ./libclassrec.so -o maindrec

.PHONY: all recursived loopd loops recursives clean

clean:
	rm mains maindrec maindloop *.so *.o *.a
