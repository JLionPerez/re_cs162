exe: main.o ant.o menu.o
	g++ main.o ant.o menu.o -o exe

main.o: main.cpp
	g++ -g -c main.cpp

ant.o: ant.cpp ant.hpp
	g++ -g -c ant.cpp

menu.o: menu.cpp menu.hpp
	g++ -g -c menu.cpp

clean:
	rm *.o exe