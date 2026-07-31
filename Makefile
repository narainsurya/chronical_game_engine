all: chronicle

console.o: ./src/console.cpp
	g++ -Wall -I ./include/ -c -o console.o ./src/console.cpp

main.o: ./src/main.cpp
	g++ -Wall -I ./include/ -c -o main.o ./src/main.cpp

chronicle: console.o main.o
	g++ console.o main.o -o chronicle
	
clean:
	rm -f *.o chronicle
