all: main boid flock vmath link
	./app

flock: Flock.cpp
	g++ -c Flock.cpp -o flock.o

vmath: VMath.cpp
	g++ -c VMath.cpp -o vmath.o

boid: PreyBoid.cpp 
	g++ -c Boid.cpp -o boid.o

main: main.cpp 
	g++ -c main.cpp -o main.o

link:
	g++ boid.o flock.o main.o vmath.o -o app -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm app main.o flock.o boid.o vmath.o 
