all: chronicle

CC := g++
CCFLAGS := -Wall -I ./include/ -c

console.o: ./src/console.cpp
	$(CC) $(CCFLAGS) -o console.o ./src/console.cpp

command.o: ./src/command.cpp
	$(CC) $(CCFLAGS) -o command.o ./src/command.cpp

world.o: ./src/world.cpp
	$(CC) $(CCFLAGS) -o world.o ./src/world.cpp

main.o: ./src/main.cpp
	$(CC) $(CCFLAGS) -o main.o ./src/main.cpp

chronicle: console.o main.o command.o world.o
	g++ console.o main.o command.o world.o -o chronicle

clean:
	rm -f *.o chronicle