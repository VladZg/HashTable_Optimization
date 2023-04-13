CC = g++
FLAGS = #-fsanitize=address

TARGET = main

SRC_DIR = ./Source
OBJ_DIR = ./Object

LIBS = ./Libs/List/Source/List.cpp

all: compile run

# parse:
# 	cd ./Data
# 	make
# 	cd ../

compile:
	g++ ./$(TARGET).cpp $(SRC_DIR)/HashFunctions.cpp $(SRC_DIR)/HashTable.cpp $(LIBS) $(FLAGS) -o $(TARGET)

run:
	./$(TARGET)

valgrind_check:
	g++ ./main.cpp ./Source/HashFunctions.cpp ./Source/HashTable.cpp ./Libs/List/Source/List.cpp -g -O0 -o vgcheck
	valgrind ./vgcheck

clean:
	rm main
