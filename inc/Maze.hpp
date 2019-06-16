#ifndef __MAZE__
#define __MAZE__

class Maze;

#include <iostream>
#include <ostream>
#include <chrono>
#include <vector>
#include <thread>

#include "Direction.hpp"
#include "MazeGenerator.hpp"

#define CLEAR "clear"
#define elif else if
#define sleep(a) std::this_thread::sleep_for(std::chrono::milliseconds(a))

class Maze{
    public:
        enum class Cell{WALL, EMPTY, NO_TYPE};

        Maze(int n, int m, int px, int py);

        void movePlayer(Direction dir);

        const Cell at(int x, int y) const;

        void printAll() const;
        void printPlayer() const;

    private:
        int n_, m_;
        int px_, py_;
        std::vector<std::vector<Cell> > matr_;

        friend MazeGenerator;
};
std::ostream & operator<<(std::ostream & out, Maze::Cell cell);
#endif