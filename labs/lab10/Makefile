exe: main.o fib_nr.o fib_r.o
	g++ main.o fib_r.o fib_nr.o -o exe

main.o: main.cpp
	g++ -std=c++11 -g -c main.cpp

fib_nr.o: fib_nr.cpp fib_nr.hpp
	g++ -std=c++11 -g -c fib_nr.cpp

fib_r.o: fib_r.cpp fib_r.hpp
	g++ -std=c++11 -g -c fib_r.cpp

clean:
	rm *.o exe