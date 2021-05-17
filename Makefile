INCLUDES = -I ./include
FLAGS = -g

OBJECTS=./build/chip8_memory.o
all: ${OBJECTS}
	gcc ${FLAGS} $(INCLUDES) -lSDL2 ./src/main.c ${OBJECTS} -o ./bin/main

./build/chip8_memory.o:src/chip8_memory.c
	gcc ${FLAGS} ${INCLUDES} ./src/chip8_memory.c -c -o ./build/chip8_memory.o

clean:
	rm -rf ./build/*
