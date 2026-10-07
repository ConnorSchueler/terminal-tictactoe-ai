CXX = g++
CXX_FLAGS = -std=c++20 -Wall -Wextra -Wshadow -Iinclude
TARGET = tictactoe-ai

SOURCES = sources/main.cpp sources/board.cpp
HEADERS = include/board.hpp include/macros.hpp

$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXX_FLAGS) $(SOURCES) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)