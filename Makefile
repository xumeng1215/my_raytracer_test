all: run

run: clean build execute

clean:
	rm -f image.ppm

build:
	c++ main.cpp

execute:
	./a.out >> image.ppm