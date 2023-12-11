CC = gcc
CFLAGS = -Wall
main: main.o BDD.o InitStruct.o moteur.o
	$(CC) $(CFLAGS) -o main main.o BDD.o InitStruct.o moteur.o -lsqlite3
main.o: main.c BDD.h InitStruct.h moteur.h includeGlobal.h
	$(CC) $(CFLAGS) -c main.c
BDD.o: BDD.c BDD.h
	$(CC) $(CFLAGS) -c BDD.c
InitStruct.o: InitStruct.c InitStruct.h
	$(CC) $(CFLAGS) -c InitStruct.c
moteur.o: moteur.c moteur.h
	$(CC) $(CFLAGS) -c moteur.c
clean:
	rm -f *.o
dpClean:
	rm -f *.o
	rm main
