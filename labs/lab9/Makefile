#
# File name: Makefile
# Purpose: Compiles files altogether.
#

exe: main.o menu.o
	g++ main.o menu.o -o exe

main.o: main.cpp
	g++ -g -c main.cpp

menu.o: menu.cpp menu.hpp
	g++ -g -c menu.cpp

clean:
	rm *.o exe
