CC = g++
flags = -std=c++11 -Wextra -Wundef -Werror -Wuninitialized -Winit-self
#IMPORTANTE AGREGAR -Wall para poner bien las flags
p: main.o
	$(CC) $(flags) -o p main.o
main.o:
	$(CC) $(flags) -c main.cpp -o main.o

run: p
	./p

clean:
	rm -rf *.o p