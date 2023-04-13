TARGET = test

CC = g++
CFLAGS = -g

TEST_DIR = ./Test/
SRC_DIR = ./Source/
ROOT_DIR = ./

SRC = 	$(TEST_DIR)Test.cpp		\
		$(SRC_DIR)List.cpp

all: create_dirs $(TARGET)

create_dirs :
	[ ! -d ./ListDump ] && mkdir -p ./ListDump ./ListDump/GraphDumpImages

$(TARGET) :
	$(CC) $(CFLAGS) $(SRC) -o $(ROOT_DIR)$(TARGET)

clean : clean_files clean_dirs

clean_files :
	rm -f *.o $(ROOT_DIR)$(TARGET)

clean_dirs :
	[ -d ./ListDump ] && rm -R ./ListDump
