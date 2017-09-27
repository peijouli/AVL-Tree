CXX = g++
CXXFLAGS = -g -Wall -std=c++11
BIN_DIR = bin
GTEST_LL = -I/usr/include/gtest -l gtest -l gtest_main -pthread

all: avlbst_test floorplan

floorplan: floorplan.cpp bst.h avlbst.h
	$(CXX) $(CXXFLAGS) floorplan.cpp -o floorplan

avlbst_test: avlbst_test.cpp  $(BIN_DIR)/.dirstamp
	$(CXX) $(CXXFLAGS) avlbst_test.cpp $(GTEST_LL) -o $(BIN_DIR)/avlbst_test
.PHONY: clean

clean:
	rm -rf $(BIN_DIR)

$(BIN_DIR)/.dirstamp:
	mkdir -p $(BIN_DIR)
	touch $(BIN_DIR)/.dirstampsu