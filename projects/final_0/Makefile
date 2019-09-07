#
# File name: Makefile
# Purpose: Compiles everything together
#

lib = g++ -std=c++11 -g -c

exe: main.o game.o player.o spaces.o jester.o magician.o gates.o highest.o
	g++ main.o game.o player.o spaces.o jester.o magician.o gates.o highest.o -o exe

main.o: main.cpp
	$(lib) main.cpp

game.o: game.cpp game.hpp
	$(lib) game.cpp

player.o: player.cpp player.hpp
	$(lib) player.cpp

spaces.o: spaces.cpp spaces.hpp
	$(lib) spaces.cpp

jester.o: jester.cpp jester.hpp
	$(lib) jester.cpp

magician.o: magician.cpp magician.hpp
	$(lib) magician.cpp

gates.o: gates.cpp gates.hpp
	$(lib) gates.cpp

highest.o: highest.cpp highest.hpp
	$(lib) highest.cpp

clean:
	rm *.o exe