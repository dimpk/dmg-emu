CXX = g++
CXXFLAGS = -Wall -g

SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)

src/%.o: src/%.cpp
	$(CXX) -c $< $(CXXFLAGS) -o $@

dmg-emu: $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f src/*.o dmg-emu
