exe: main.o game.o die.o loaded_die.o
	g++ main.o game.o die.o loaded_die.o -o exe

main.o: main.cpp
	g++ -g -c main.cpp

game.o: game.cpp game.hpp
	g++ -g -c game.cpp

die.o: die.cpp die.hpp
	g++ -g -c die.cpp

loaded_die.o: loaded_die.cpp loaded_die.hpp
	g++ -g -c loaded_die.cpp

clean:
	rm *.o exe