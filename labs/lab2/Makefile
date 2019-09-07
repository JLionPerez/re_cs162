#
# File name: Makefile
# Purpose: Compiles files altogether.
#
exe: main.o frequency.o
	g++ main.o frequency.o -o exe

main.o: main.cpp
	g++ -g -c main.cpp

read_matrix.o: frequency.cpp frequency.hpp
	g++ -g -c frequency.cpp
clean:
	rm *.o exe