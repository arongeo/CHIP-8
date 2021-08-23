cmake_minimum_required(VERSION 3.10)

project(CHIP-8)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(INCLUDE_DIR include)
find_package(SDL2 REQUIRED)
include_directories(${INCLUDE_DIR})
link_libraries(SDL2::SDL2)
set(ALL_SOURCES
	${INCLUDE_DIR}/config.h ${INCLUDE_DIR}/chip8_stack.h ${INCLUDE_DIR}/chip8_memory.h ${INCLUDE_DIR}/chip8_display.h ${INCLUDE_DIR}/chip8_keyboard.h ${INCLUDE_DIR}/chip8_registers.h ${INCLUDE_DIR}/chip8.h src/chip8_stack.c src/chip8_memory.c src/chip8_display.c src/chip8_keyboard.c src/chip8.c src/main.c
)
add_executable(chip8 ${ALL_SOURCES})
