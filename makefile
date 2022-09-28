# Directories:

SRC_DIR=./src/
HEADERS_DIR=./headers/
OBJECTS_DIR=./object/

# Files:

FILES = stats timer warmup
OBJS = $(patsubst %, %.o, $(FILES))

# Compiler:

CXX=g++
CXXFLAGS=-O0 -g -Wall

# Commands:

launch:	build run

run:	
		./cmd

build:	$(SRC_DIR)main.cpp $(OBJS)
		$(CXX) $(CXXFLAGS) $< $(wildcard $(addprefix $(OBJECTS_DIR),$(OBJS))) -o cmd

%.o:	$(SRC_DIR)%.cpp $(HEADERS_DIR)%.hpp
		mkdir -p $(OBJECTS_DIR)
		$(CXX) $(CXXFLAGS) -c $< -o $(OBJECTS_DIR)$@ 