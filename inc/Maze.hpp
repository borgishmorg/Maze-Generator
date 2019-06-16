#pragma once

class Maze;

#include <iostream>
#include <chrono>
#include <thread>

#include "MazeGenerator.hpp"

#define CLEAR "clear"
#define elif else if
#define sleep(a) std::this_thread::sleep_for(std::chrono::milliseconds(a))

class Maze{
    public:
        Maze(int n, int m, int px, int py);

        void printAll() const;
        void printPlayer() const;
    private:
        int n_, m_;
        int px_, py_;
        char matr_[1001][1001];

        friend MazeGenerator;
};