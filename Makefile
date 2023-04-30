CC = g++
FLAGS = -w -O3 #-fsanitize=leak

TARGET = HashFuncsAnalyze
# TARGET = HashTableOpt

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

callgrind_check:
	valgrind --tool=callgrind ./HashTableOpt
#    kcachegrind callgrind.out
# mv callgrind.out ./Valgrind

clean:
	rm ./$(TARGET)
