CC = gcc
CFLAGS = -g -Wall

all : loops recursives recursived loopd mains maindloop maindrec

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

libclassloops.so : basicClassification.c advancedClassificationLoop.o
	$(CC) $(CFLAGS) -fPIC -c basicClassification.c advancedClassificationLoop.c
	$(CC) $(CFLAGS) -shared basicClassification.o advancedClassificationLoop.o -o libclassloops.so
	export LD_LIBRARY_PATH=.:$$LD_LIBRARY_PATH

mains : main.o libclassrec.a
	$(CC) $(CFLAGS) main.o -lclassrec -L. -o mains

maindloop : main.c libclassloops.so
	$(CC) $(CFLAGS) -c main.c -L. -lclassloops -o maindloop

maindrec: main.c libclassrec.so
	$(CC) $(CFLAGS) -c main.c -L. -lclassrec -o maindrec

clean:
	rm mains maindrec maindloop *.so *.o *.a
