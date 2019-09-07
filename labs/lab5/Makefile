exe: main.o menu.o recursive.o
	g++ main.o menu.o recursive.o -o exe

main.o: main.cpp
	g++ -g -c main.cpp

menu.o: menu.hpp menu.cpp
	g++ -g -c menu.cpp

recursive.o: recursive.hpp recursive.cpp
	g++ -g -c recursive.cpp

clean:
	rm *.o exe