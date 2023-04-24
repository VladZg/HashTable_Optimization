CC = g++
FLAGS = #-fsanitize=leak

TARGET = app

SRC_DIR = ./Source
OBJ_DIR = ./Object

LIBS = ./Libs/List/Source/List.cpp

all: compile run

# parse:
# 	cd ./Data
# 	make
# 	cd ../

compile:
	@g++ $(SRC_DIR)/*.cpp $(LIBS) ./$(TARGET).cpp $(FLAGS) -o $(TARGET)

run:
	@./$(TARGET)

valgrind_check:
	g++ $(SRC_DIR)/*.cpp $(LIBS) ./$(TARGET).cpp -g -O0 -o vgcheck
	valgrind ./vgcheck

clean:
	rm main
