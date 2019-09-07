#
# File name: Makefile
# Purpose: Compiles all files together
#

exe: main.o search_sort.o
	g++ main.o search_sort.o -o exe

main.o: main.cpp
	g++ -g -c main.cpp

search_sort.o: search_sort.cpp search_sort.hpp
	g++ -g -c search_sort.cpp

clean:
	rm *.o exe