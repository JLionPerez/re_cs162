#Based on: https://www.youtube.com/watch?v=_r7i5X0rXJk
#target: dependencies
#		action
exe: main.o read_matrix.o determinant.o
	g++ main.o read_matrix.o determinant.o -o exe

main.o: main.cpp
	g++ -g -c main.cpp

read_matrix.o: read_matrix.cpp read_matrix.hpp
	g++ -g -c read_matrix.cpp

determinant.o: determinant.cpp determinant.hpp
	g++ -g -c determinant.cpp

clean:
	rm *.o exe