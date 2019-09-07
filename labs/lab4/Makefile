#
# File name: Makefile
# Purpose: Compiles files altogether.
#

exe: main.o menu.o university.o building.o person.o instructor.o student.o
	g++ main.o menu.o university.o building.o person.o instructor.o student.o -o exe

main.o: main.cpp
	g++ -g -c main.cpp

menu.o: menu.cpp menu.hpp
	g++ -g -c menu.cpp

university.o: university.cpp university.hpp
	g++ -g -c university.cpp

building.o: building.cpp building.hpp
	g++ -g -c building.cpp

person.o: person.cpp person.hpp
	g++ -g -c person.cpp

instructor.o: instructor.cpp instructor.hpp
	g++ -g -c instructor.cpp

student.o: student.cpp student.hpp
	g++ -g -c student.cpp

clean:
	rm *.o exe