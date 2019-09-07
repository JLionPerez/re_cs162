#
# File name: Makefile
# Purpose: Compiles multiple files together
#

exe: main.o menu.o characters.o barbarian.o blue_men.o harry_potter.o medusa.o vampires.o
	g++ main.o menu.o characters.o barbarian.o blue_men.o harry_potter.o medusa.o vampires.o -o exe

main.o: main.cpp
	g++ -c -g main.cpp

menu.o: menu.cpp menu.hpp
	g++ -c -g menu.cpp

characters.o: characters.cpp characters.hpp
	g++ -c -g characters.cpp

barbarian.o: barbarian.cpp barbarian.hpp
	g++ -c -g barbarian.cpp

blue_men.o: blue_men.cpp blue_men.hpp
	g++ -c -g blue_men.cpp

harry_potter.o: harry_potter.cpp harry_potter.hpp
	g++ -c -g harry_potter.cpp

medusa.o: medusa.cpp medusa.hpp
	g++ -c -g medusa.cpp

vampires.o: vampires.cpp vampires.hpp
	g++ -c -g vampires.cpp

clean:
	rm *.o exe