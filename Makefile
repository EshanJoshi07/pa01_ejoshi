# Makefile
CXX_FLAG = --std=c++11 -g

all: game

game: main.o cards.o
	g++ $(CXX_FLAG) -o game main.o cards.o

main.o: main.cpp
	g++ $(CXX_FLAG) -c main.cpp

cards.o: cards.cpp cards.h
	g++ $(CXX_FLAG) -c cards.cpp

clean:
	rm *.o game
