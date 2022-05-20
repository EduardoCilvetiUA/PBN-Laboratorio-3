CC = g++
flags = 
#IMPORTANTE AGREGAR -Wall para poner bien las flags
p: main.o peleador.o
	$(CC) $(flags) -o p main.o peleador.o
main.o: main.cpp
	$(CC) $(flags) -c main.cpp -o main.o

peleador.o: peleador.cpp
	$(CC) $(flags) -c peleador.cpp -o peleador.o

run: p
	./p

clean:
	rm *.o p