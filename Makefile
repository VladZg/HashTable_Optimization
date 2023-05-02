CC = g++
FLAGS = -w -O3 -mavx2 #-fsanitize=leak

# TARGET = HashFuncsAnalyze
TARGET = HashTableOpt

SRC_DIR = ./Source
OBJ_DIR = ./Object

LIBS = ./Libs/List/Source/List.cpp

all: compile link run

# parse:
# 	cd ./Data
# 	make
# 	cd ../

compile:
	@g++  $(FLAGS) -c $(SRC_DIR)/HashFunctions.cpp -o $(OBJ_DIR)/HashFunctions.o
	@g++  $(FLAGS) -c $(SRC_DIR)/HashTable.cpp -o $(OBJ_DIR)/HashTable.o
	@g++  $(FLAGS) -c $(LIBS) -o $(OBJ_DIR)/List.o
	@g++  $(FLAGS) -c ./HashTableOpt.cpp -o $(OBJ_DIR)/HashTableOpt.o
	@nasm -f elf64 -g $(SRC_DIR)/Crc32Hash.s -o $(OBJ_DIR)/Crc32Hash.o

link:
	@g++ $(OBJ_DIR)/*.o -o ./$(TARGET)

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
