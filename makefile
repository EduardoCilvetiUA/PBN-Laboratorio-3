CC = g++
flags = -std=c++11 -Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self
#IMPORTANTE AGREGAR -Wall para poner bien las flags
p: main.o peleador.o objeto.o arena.o
	$(CC) $(flags) main.o peleador.o objeto.o arena.o -o p
main.o: main.cpp
	$(CC) $(flags) -c main.cpp -o main.o

peleador.o: peleador.cpp
	$(CC) $(flags) -c peleador.cpp -o peleador.o

objeto.o: objeto.cpp
	$(CC) $(flags) -c objeto.cpp -o objeto.o

arena.o: arena.cpp
	$(CC) $(flags) -c arena.cpp -o arena.o

mocha: p
	./p

clean:
	del main.o peleador.o objeto.o arena.o OUTPUT.txt