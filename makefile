all: main preyboid flock vmath link
	./app

flock: Flock.cpp
	g++ -c Flock.cpp -o flock.o

vmath: VMath.cpp
	g++ -c VMath.cpp -o vmath.o

preyboid: PreyBoid.cpp 
	g++ -c PreyBoid.cpp -o preyboid.o

main: main.cpp 
	g++ -c main.cpp -o main.o

link:
	g++ preyboid.o flock.o main.o vmath.o -o app -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm app main.o flock.o boid.o vmath.o 
