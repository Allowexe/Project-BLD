CC = gcc
CFLAGS = -Wall

main: main.o BDD.o InitStruct.o moteur.o affichage.o
	$(CC) $(CFLAGS) -o main main.o BDD.o InitStruct.o moteur.o affichage.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

BDD.o: BDD.c
	$(CC) $(CFLAGS) -c BDD.c

InitStruct.o: InitStruct.c
	$(CC) $(CFLAGS) -c InitStruct.c

moteur.o: moteur.c
	$(CC) $(CFLAGS) -c moteur.c
	
affichage.o: affichage.c
	$(CC) $(CFLAGS) -c affichage.c

clean:
	rm -f *.o
	rm -f mainclean:p
	rm -f *.o clean main
