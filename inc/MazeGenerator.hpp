#ifndef __MAZE_GENERATOR__
#define __MAZE_GENERATOR__

class MazeGenerator;

#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>

#include "Maze.hpp"

class MazeGenerator{
    public:
        enum class Type{BFS, DFS, EDGE};

        MazeGenerator();

        Maze getMaze() const;

        void setType(Type type);
        void setSize(int n, int m);
        void setPlayerPos(int x0, int y0);
        void setAnimation(bool);
    private:
        void generBFSMaze(int x, int y, Maze & maze) const;
        void generDFSMaze(int x, int y, Maze & maze) const;
        void generEdgeMaze(int x, int y, Maze & maze) const;

        int n_, m_;
        int x0_, y0_;
        Type type_;
        bool animated_;

        static const int dx_[];
        static const int dy_[];
};
#endif