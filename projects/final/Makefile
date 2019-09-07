lib = -std=c++11 -g -c

exe: main.o menu.o game.o space.o beach.o cabin.o desert.o forest.o lake.o roses.o characters.o snake.o mermaid.o dog.o mare.o
	g++ main.o menu.o game.o space.o beach.o cabin.o desert.o forest.o lake.o roses.o characters.o snake.o mermaid.o dog.o mare.o -o exe

main.o: main.cpp
	g++ $(lib) main.cpp

menu.o: menu.cpp menu.hpp
	g++ $(lib) menu.cpp

game.o: game.cpp game.hpp
	g++ $(lib) game.cpp

space.o: space.cpp space.hpp
	g++ $(lib) space.cpp

beach.o: beach.cpp beach.hpp
	g++ $(lib) beach.cpp

cabin.o: cabin.cpp cabin.hpp
	g++ $(lib) cabin.cpp

desert.o: desert.cpp desert.hpp
	g++ $(lib) desert.cpp

forest.o: forest.cpp forest.hpp
	g++ $(lib) forest.cpp

lake.o: lake.cpp lake.hpp
	g++ $(lib) lake.cpp

roses.o: roses.cpp roses.hpp
	g++ $(lib) roses.cpp

characters.o: characters.cpp characters.hpp
	g++ $(lib) characters.cpp

snake.o: snake.cpp snake.hpp
	g++ $(lib) snake.cpp

mermaid.o: mermaid.cpp mermaid.hpp
	g++ $(lib) mermaid.cpp

dog.o: dog.cpp dog.hpp
	g++ $(lib) dog.cpp

mare.o: mare.cpp mare.hpp
	g++ $(lib) mare.cpp

clean:
	rm *.o exe