# strangerThings (Final Project: 'A Text-based Game') makefile -- Will Clayton

strangerThings: wcLibrary.o Space.o NormalSpace.o DoorSpace.o LightSpace.o PortalSpace.o Game.o Item.o strangerThings.o
	g++ wcLibrary.o Space.o NormalSpace.o DoorSpace.o LightSpace.o PortalSpace.o Game.o Item.o strangerThings.o -o strangerThings

wcLibrary.o: wcLibrary.hpp wcLibrary.cpp
	g++ -c wcLibrary.cpp

Space.o: Space.hpp Space.cpp
	g++ -c Space.cpp

NormalSpace.o: NormalSpace.hpp NormalSpace.cpp
	g++ -c NormalSpace.cpp

DoorSpace.o: DoorSpace.hpp DoorSpace.cpp
	g++ -c DoorSpace.cpp

LightSpace.o: LightSpace.cpp LightSpace.cpp
	g++ -c LightSpace.cpp

PortalSpace.o: PortalSpace.hpp PortalSpace.cpp
	g++ -c PortalSpace.cpp

Item.o: Item.cpp Item.hpp
	g++ -c Item.cpp

Game.o: Game.hpp Game.cpp
	g++ -c Game.cpp

strangerThings.o: strangerThings.cpp
	g++ -c strangerThings.cpp

clean: 
	rm -f *.o strangerThings

.PHONY: valgrind
valgrind:
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes ./strangerThings

.PHONY:
zip:
	zip FinalProject_Clayton_Will.zip makefile wcLibrary.hpp wcLibrary.cpp Space.hpp Space.cpp NormalSpace.hpp NormalSpace.cpp DoorSpace.hpp DoorSpace.cpp LightSpace.hpp LightSpace.cpp PortalSpace.hpp PortalSpace.cpp Item.hpp Item.cpp Game.hpp Game.cpp strangerThings.cpp FinalProject_Design_Reflection.pdf
