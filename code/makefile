# Directories:

SRC_DIR=./src/
HEADERS_DIR=./headers/
OBJECTS_DIR=./object/

# Files:

FILES = stats timer warmup
OBJS = $(patsubst %, %.o, $(FILES))

# Compiler:

CXX=g++
CXXFLAGSOPTDIS=-O0
CXXFLAGSOPTEN=-O3 

# Commands:

asm:		build
		    objdump -d cmd

launch:		build run

run:	
			./cmd

build:		$(SRC_DIR)main.cpp $(OBJS)
			$(CXX) $(CXXFLAGSOPTDIS) $< $(wildcard $(addprefix $(OBJECTS_DIR),$(OBJS))) -o cmd
			rm -r $(OBJECTS_DIR)

stats.o:	$(SRC_DIR)stats.cpp $(HEADERS_DIR)stats.hpp
			mkdir -p $(OBJECTS_DIR)
			$(CXX) $(CXXFLAGSOPTEN) -c $< -o $(OBJECTS_DIR)$@ 

timer.o:	$(SRC_DIR)timer.cpp $(HEADERS_DIR)timer.hpp
			mkdir -p $(OBJECTS_DIR)
			$(CXX) $(CXXFLAGSOPTDIS) -c $< -o $(OBJECTS_DIR)$@ 

warmup.o:	$(SRC_DIR)warmup.cpp $(HEADERS_DIR)warmup.hpp
			mkdir -p $(OBJECTS_DIR)
			$(CXX) $(CXXFLAGSOPTDIS) -c $< -o $(OBJECTS_DIR)$@