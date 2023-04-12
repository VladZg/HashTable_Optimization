CC = g++
FLAGS =

TARGET = main

SRC_DIR = ./Source
OBJ_DIR = ./Object

all: compile run

compile:
	g++ ./$(TARGET).cpp $(SRC_DIR)/HashFunctions.cpp -o $(TARGET)

run:
	./$(TARGET)

clean:
	rm main
