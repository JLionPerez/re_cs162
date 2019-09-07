#
# File name: Makefile
# Purpose: Compiles files altogether
#

exe: main.o zoo.o animal.o penguin.o turtle.o tiger.o
	g++ main.o zoo.o animal.o penguin.o turtle.o tiger.o -o exe

main.o: main.cpp
	g++ -g -c main.cpp

zoo.o: zoo.cpp zoo.hpp
	g++ -g -c zoo.cpp

animal.o: animal.cpp animal.hpp
	g++ -g -c animal.cpp

penguin.o: penguin.cpp penguin.hpp
	g++ -g -c penguin.cpp

turtle.o: turtle.cpp turtle.hpp
	g++ -g -c turtle.cpp

tiger.o: tiger.cpp tiger.hpp
	g++ -g -c tiger.cpp

clean:
	rm *.o exe