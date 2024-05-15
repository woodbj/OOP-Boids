all: main boid flock vmath drawhelper link 
	./app

link:
	g++ boid.o flock.o main.o vmath.o drawhelper.o -o app -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm app main.o flock.o boid.o vmath.o 

main: main.cpp 
	g++ -c main.cpp -o main.o

flock: Flock.cpp
	g++ -c Flock.cpp -o flock.o

boid: Boid.cpp 
	g++ -c Boid.cpp -o boid.o

vmath: VMath.cpp
	g++ -c VMath.cpp -o vmath.o

drawhelper: DrawHelper.cpp
	g++ -c DrawHelper.cpp -o drawhelper.o




