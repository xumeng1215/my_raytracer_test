CC = gcc
CFLAGS = -std=c11 -Wall -Wextra
INCLUDE_DIR = include
TARGET = my_raytracer
SRC = $(wildcard src/*.c)

all: run

run: clean build execute

clean:
	rm -f image.ppm $(TARGET)

build:
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -o $(TARGET) $(SRC) -lm

execute:
	./$(TARGET) >> image.ppm