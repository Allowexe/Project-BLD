main: main.o bdd.o InitStruct.o moteur.o
	gcc -Wall -o main main.o bdd.o InitStruct.o moteur.o 

main.o: main.c bdd.h InitStruct.h moteur.h
	gcc -Wall -c main.c

bdd.o: bdd.c bdd.h
	gcc -Wall -c bdd.c

InitStruct.o: InitStruct.c InitStruct.h
	gcc -Wall -c InitStruct.c

moteur.o: moteur.c moteur.h
	gcc -Wall -c moteur.c

clean:
	rm -f *.o

dpClean:
	rm -f *.o
	rm main
