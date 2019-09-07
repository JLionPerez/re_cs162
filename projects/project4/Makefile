#
# File name: Makefile
# Purpose: Compiles multiple files together
#

exe: main.o menu.o containers.o characters.o barbarian.o blue_men.o harry_potter.o medusa.o vampires.o
	g++ -std=c++11 main.o menu.o containers.o characters.o barbarian.o blue_men.o harry_potter.o medusa.o vampires.o -o exe

main.o: main.cpp
	g++ -std=c++11 -c -g main.cpp

menu.o: menu.cpp menu.hpp
	g++ -std=c++11 -c -g menu.cpp

containers.o: containers.cpp containers.hpp
	g++ -std=c++11 -c -g containers.cpp

characters.o: characters.cpp characters.hpp
	g++ -std=c++11 -c -g characters.cpp

barbarian.o: barbarian.cpp barbarian.hpp
	g++ -std=c++11 -c -g barbarian.cpp

blue_men.o: blue_men.cpp blue_men.hpp
	g++ -std=c++11 -c -g blue_men.cpp

harry_potter.o: harry_potter.cpp harry_potter.hpp
	g++ -std=c++11 -c -g harry_potter.cpp

medusa.o: medusa.cpp medusa.hpp
	g++ -std=c++11 -c -g medusa.cpp

vampires.o: vampires.cpp vampires.hpp
	g++ -std=c++11 -c -g vampires.cpp

clean:
	rm *.o exe