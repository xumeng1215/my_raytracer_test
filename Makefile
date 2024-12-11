CXX = c++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGET = my_raytracer

all: run

run: clean build execute

clean:
	rm -f image.ppm $(TARGET)

build:
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.cpp

execute:
	./$(TARGET) >> image.ppm