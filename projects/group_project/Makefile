exe: cs162_group10_project.o validation.o Simulation.o Critter.o Ant.o Doodlebug.o
	g++ cs162_group10_project.o validation.o Simulation.o Critter.o Ant.o Doodlebug.o -o exe

cs162_group10_project.o: cs162_group10_project.cpp 
	g++ -c -g cs162_group10_project.cpp

#menu.o: menu.cpp menu.h
#	g++ -c -g menu.cpp

validation.o: validation.cpp validation.h
	g++ -c -g validation.cpp

Simulation.o: Simulation.cpp Simulation.h
	g++ -c -g Simulation.cpp

Critter.o: Critter.cpp Critter.h
	g++ -c -g Critter.cpp

Ant.o: Ant.cpp Ant.h
	g++ -c -g Ant.cpp

Doodlebug.o: Doodlebug.cpp Doodlebug.h
	g++ -c -g Doodlebug.cpp

clean:
	rm *.o exe