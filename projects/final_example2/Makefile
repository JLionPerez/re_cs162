vimCXX = g++
CXXFLAGS = -std=c++0x
OBJS = utlty.o m3nu.o final2.o bongo.o cobra.o cobraRoom.o entryRoom.o firePit.o flute.o pawn.o player.o rattleRoom.o rattleSnake.o room.o snake.o snakeGodRoom.o snakeRoom.o torch.o wall.o wind.o windRoom.o 
SRCS = utlty.cpp m3nu.cpp final2.cpp bongo.cpp cobra.cpp cobraRoom.cpp entryRoom.cpp firePit.cpp flute.cpp pawn.cpp player.cpp rattleRoom.cpp rattleSnake.cpp room.cpp snake.cpp snakeGodRoom.cpp snakeRoom.cpp torch.cpp wall.cpp wind.cpp windRoom.cpp
HEADERS = utlty.hpp m3nu.hpp bongo.hpp cobra.hpp cobraRoom.hpp entryRoom.hpp firePit.hpp flute.hpp pawn.hpp player.hpp rattleRoom.hpp rattleSnake.hpp room.hpp snake.hpp snakeGodRoom.hpp snakeRoom.hpp torch.hpp wall.hpp wind.hpp windRoom.hpp
final: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o final
clean:
	rm -f final *.o
