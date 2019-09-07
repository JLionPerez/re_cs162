exe: main.o node.o
	g++ main.o node.o -o exe

main.o: main.cpp
	g++ -c -g main.cpp

node.o: node.cpp node.hpp
	g++ -c -g node.cpp

clean:
	rm *.o exe