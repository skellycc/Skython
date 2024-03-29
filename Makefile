STD_VER 	:= -std=c++11
INCLUDES 	:= -Iinclude
SOURCES		:= ./Source/compiler/lex/*.cc ./Source/compiler/gram/*.cc ./Source/compiler/gram/stage1/*.cc ./Source/compiler/parser/*.cc
BUILD_LOC	:= ./build/skcc

all: clean
	mkdir build
	g++ $(STD_VER) $(INCLUDES) ./Source/main.cc $(SOURCES) -o $(BUILD_LOC)

clean:
	rm -rf build
	
run:
	./build/skcc

.PHONY: all
