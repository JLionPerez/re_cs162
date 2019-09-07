exe: main.o menu.o queue.o
	g++ -std=c++11 main.o menu.o queue.o -o exe

main.o: main.cpp
	g++ -std=c++11 -g -c main.cpp

menu.o: menu.cpp menu.hpp
	g++ -std=c++11 -g -c menu.cpp

queue.o: queue.cpp queue.hpp
	g++ -std=c++11 -g -c queue.cpp

clean:
	rm *.o exe