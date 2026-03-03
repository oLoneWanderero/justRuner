CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

SRC = $(wildcard src/*.cpp)
OBJ = $(patsubst src/%.cpp, build/%.o, $(SRC))

TARGET = build/game

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@
	rm -f $(OBJ)

build/%.o: src/%.cpp
	mkdir -p build
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf build