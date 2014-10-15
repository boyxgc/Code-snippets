SRC_DIR = .

CPP_SOURCES = $(shell find $(SRC_DIR) -name "*.cpp")
CPP_OBJECTS = $(patsubst %.cpp,%.o,${CPP_SOURCES})

NEW_CPP_SOURCES = ${shell find $(SRC_DIR) -type f -mtime -1 -name "*.cpp"}
NEW_CPP_OBJECTS = $(patsubst %.cpp,%.o,${NEW_CPP_SOURCES})

all: clean build

new: clean buildnew

build: ${CPP_OBJECTS}

buildnew: ${NEW_CPP_OBJECTS}

%.o: %.cpp
	g++ -Wall $< -o $@

clean:
	rm -rf *.o *.dSYM
