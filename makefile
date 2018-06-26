CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -g

SRCES = game.cpp space.cpp toxic_waste.cpp button.cpp floor.cpp \
		door.cpp wall.cpp chamberlock.cpp item.cpp player.cpp worldMap.cpp \
		utils.cpp main.cpp
HDRS =  game.hpp space.hpp toxic_waste.hpp button.hpp floor.hpp \
		door.hpp wall.hpp chamberlock.hpp item.hpp player.hpp worldMap.hpp \
		utils.hpp
OBJS =  game.o space.o toxic_waste.o button.o floor.o door.o wall.o \
		chamberlock.o item.o player.o worldMap.o utils.o main.o

portal: ${OBJS} 
	${CXX} ${CXXFLAGS} ${OBJS} -o portal -ggdb

game.o: game.cpp game.hpp
	${CXX} ${CXXFLAGS} -c game.cpp

space.o: space.cpp space.hpp
	${CXX} ${CXXFLAGS} -c space.cpp

toxic_waste.o: toxic_waste.cpp toxic_waste.hpp
	${CXX} ${CXXFLAGS} -c toxic_waste.cpp

button.o: button.cpp button.hpp
	${CXX} ${CXXFLAGS} -c button.cpp

floor.o: floor.cpp floor.hpp
	${CXX} ${CXXFLAGS} -c floor.cpp

door.o: door.cpp door.hpp
	${CXX} ${CXXFLAGS} -c door.cpp

wall.o: wall.cpp wall.hpp
	${CXX} ${CXXFLAGS} -c wall.cpp

chamberlock.o: chamberlock.cpp chamberlock.hpp
	${CXX} ${CXXFLAGS} -c chamberlock.cpp

item.o: item.cpp item.hpp
	${CXX} ${CXXFLAGS} -c item.cpp

player.o: player.cpp player.hpp
	${CXX} ${CXXFLAGS} -c player.cpp

worldMap.o: worldMap.cpp worldMap.hpp
	${CXX} ${CXXFLAGS} -c worldMap.cpp

utils.o: utils.cpp utils.hpp
	${CXX} ${CXXFLAGS} -c utils.cpp

main.o: main.cpp
	${CXX} ${CXXFLAGS} -c main.cpp

clean: 
	 rm *.o portal 
