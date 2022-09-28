SRC_DIR=./src/
HEADERS_DIR=./headers/
OBJECTS_DIR=./object/

FILES = stats timer warmup

OBJS = $(patsubst %, %.o, $(FILES))

CXX=g++
CXXFLAGS=-O0 -g -Wall

cmd:	$(SRC_DIR)main.cpp $(OBJS)
		$(CXX) $(CXXFLAGS) $< $(wildcard $(addprefix $(OBJECTS_DIR),$(OBJS))) -o $@

%.o:	$(SRC_DIR)%.cpp $(HEADERS_DIR)%.hpp
		$(CXX) $(CXXFLAGS) -c $< -o $(OBJECTS_DIR)$@ 