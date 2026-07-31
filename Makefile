all: ironhold

console.o: ./src/console.cpp
	g++ -Wall -I. -c -o console.o ./src/console.cpp

main.o: ./src/main.cpp
	g++ -Wall -I. -c -o main.o ./src/main.cpp

ironhold: console.o main.o
	g++ console.o main.o -o ironhold
	./ironhold
clean:
	rm -f *.o ironhold
