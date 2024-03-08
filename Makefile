STD_VER 	:= -std=c++11
INCLUDES 	:= -Iinclude
SOURCES		:= ./Source/compiler/lex/*.cc
BUILD_LOC	:= ./build/skcc

all: clean
	mkdir build
	g++ $(STD_VER) $(INCLUDES) ./Source/main.cc $(SOURCES) -o $(BUILD_LOC)

clean:
	rm -rf build
	
run:
	./build/skcc

.PHONY: all
