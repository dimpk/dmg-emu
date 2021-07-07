CXX = g++
CXXFLAGS = -Wall -g

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

%.o: %.cpp
	$(CXX) -c $< $(CXXFLAGS) -o $@

dmg-emu: $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f *.o dmg-emu
