# Makefile for Final Project
# Caleb Schmidt
# 10/23/2017

# C++ compiler
CXX = g++

# My preferred compiler options
CXXFLAGS = -std=c++11 -Wall -pedantic-errors -g

# Default target is to make the executable
finalproject: main.o Game.o Space.o iPhone.o DesktopPC.o Server.o WebServer.o DeviceFile.o menu.o
	$(CXX) $(CXXFLAGS) main.o Game.o Space.o iPhone.o DesktopPC.o Server.o WebServer.o DeviceFile.o menu.o -o finalproject

main.o: main.cpp Game.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Game.o: Game.hpp Game.cpp Space.hpp iPhone.hpp DesktopPC.hpp Server.hpp menu.hpp
	$(CXX) $(CXXFLAGS) -c Game.cpp

iPhone.o: iPhone.hpp iPhone.cpp Space.hpp
	$(CXX) $(CXXFLAGS) -c iPhone.cpp

DesktopPC.o: DesktopPC.hpp DesktopPC.cpp Space.hpp
	$(CXX) $(CXXFLAGS) -c DesktopPC.cpp

Server.o: Server.hpp Server.cpp Space.hpp
	$(CXX) $(CXXFLAGS) -c Server.cpp

WebServer.o: WebServer.hpp WebServer.cpp Space.hpp
	$(CXX) $(CXXFLAGS) -c WebServer.cpp

Space.o: Space.hpp Space.cpp DeviceFile.hpp
	$(CXX) $(CXXFLAGS) -c Space.cpp

DeviceFile.o: DeviceFile.hpp DeviceFile.cpp
	$(CXX) $(CXXFLAGS) -c DeviceFile.cpp

menu.o: menu.hpp menu.cpp
	$(CXX) $(CXXFLAGS) -c menu.cpp

# Remove all object files and the executable
clean:
	rm -f *.o finalproject
