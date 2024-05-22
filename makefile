all: main play boid flock vmath drawhelper pred link 
	./app

link:
	g++ play.o boid.o flock.o main.o vmath.o drawhelper.o pred.o -o app -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm app *.o 

main: main.cpp 
	g++ -c main.cpp -o main.o

flock: Flock.cpp
	g++ -c Flock.cpp -o flock.o

pred: PredBoid.cpp
	g++ -c PredBoid.cpp -o pred.o

play: PlayBoid.cpp
	g++ -c PlayBoid.cpp -o play.o

boid: Boid.cpp 
	g++ -c Boid.cpp -o boid.o

vmath: VMath.cpp
	g++ -c VMath.cpp -o vmath.o

drawhelper: DrawHelper.cpp
	g++ -c DrawHelper.cpp -o drawhelper.o
