.PHONY: all

CMP=g++ -std=c++11
INC=inc
SRC=src

all:
	$(CMP) -I$(INC) -o MazeGenerator.exe $(SRC)/*