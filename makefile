CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -g
TARGET = Aeropuerto_PP2

SRC = src/main.cpp src/pila.cpp src/dominio.cpp src/menu.cpp src/cola.cpp src/utils.cpp
OBJ = $(SRC:.cpp=.o)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
