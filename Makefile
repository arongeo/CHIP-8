INCLUDES = -I ./include
FLAGS = -g

OBJECTS=./build/chip8_display.o ./build/chip8_memory.o ./build/chip8_stack.o ./build/chip8_keyboard.o ./build/chip8.o

all: ${OBJECTS}
	gcc ${FLAGS} $(INCLUDES) -lSDL2 ./src/main.c ${OBJECTS} -o ./bin/main

./build/chip8_display.o:src/chip8_display.c
	gcc ${FLAGS} ${INCLUDES} ./src/chip8_display.c -c -o ./build/chip8_display.o

./build/chip8_memory.o:src/chip8_memory.c
	gcc ${FLAGS} ${INCLUDES} ./src/chip8_memory.c -c -o ./build/chip8_memory.o

./build/chip8_stack.o:src/chip8_stack.c
	gcc ${FLAGS} ${INCLUDES} ./src/chip8_stack.c -c -o ./build/chip8_stack.o

./build/chip8_keyboard.o:src/chip8_keyboard.c
	gcc ${FLAGS} ${INCLUDES} ./src/chip8_keyboard.c -c -o ./build/chip8_keyboard.o

./build/chip8.o:src/chip8.c
	gcc ${FLAGS} ${INCLUDES} ./src/chip8.c -c -o ./build/chip8.o

clean:
	rm -rf ./build/*
	cp ./bin/placeholder.txt ./build/placeholder.txt
	rm -rf ./bin/main
	rm -rd ./bin/main.dSYM
