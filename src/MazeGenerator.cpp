#include "MazeGenerator.hpp"

MazeGenerator::MazeGenerator():
    n_(2), m_(2), 
    x0_(1), y0_(1),
    type_(Type::BFS),
    animated_(false){}

Maze MazeGenerator::getMaze() const{
    srand(time(NULL));
    Maze maze(n_, m_, x0_, y0_);

    switch(type_){
        case Type::BFS:
            generBFSMaze(x0_, y0_, maze);
            break;
        case Type::DFS:
            generDFSMaze(x0_, y0_, maze);
            break;
        case Type::EDGE:
            generEdgeMaze(x0_, y0_, maze);
            break;
    }
    
    return std::move(maze);
}

void MazeGenerator::setType(Type type){
    type_ = type;
}

void MazeGenerator::setSize(int n, int m){
    n_ = n;
    m_ = m;
}

void MazeGenerator::setPlayerPos(int x0, int y0){
    x0_ = x0;
    y0_ = y0;
}

void MazeGenerator::setAnimation(bool animated){
    animated_ = animated;
}

void MazeGenerator::generBFSMaze(int x, int y, Maze & maze) const{
    std::queue<std::pair<int, int> > verteces;
    std::vector<int> ways = {0, 1, 2, 3};

    maze.matr_[x][y] = Maze::Cell::EMPTY;
    verteces.push({x, y});
    
    while(!verteces.empty()){
        random_shuffle(ways.begin(), ways.end());
        
        int x0 = verteces.front().first;
        int y0 = verteces.front().second;

        verteces.pop();

        for(int dir : ways){
            int nx = x0 + dx_[dir];
            int ny = y0 + dy_[dir];

            if(maze.at(nx, ny) != Maze::Cell::WALL)
                continue;

            maze.matr_[(nx + x0)/2][(ny + y0)/2] = Maze::Cell::EMPTY;
            maze.matr_[nx][ny] = Maze::Cell::EMPTY;
            verteces.push({nx, ny});

            if(animated_)
                maze.printAll();
        }
    }
}

void MazeGenerator::generDFSMaze(int x, int y, Maze & maze) const{
    maze.matr_[x][y] = Maze::Cell::EMPTY;

    std::vector<std::pair<int, int> > edge;
    edge.push_back({x, y});
    std::vector<int> ways = {0, 1, 2, 3};
    
    while(!edge.empty()){
        random_shuffle(ways.begin(), ways.end());
        
        bool inEdge = false;

        int x = edge.back().first;
        int y = edge.back().second;

        for(int dir : ways){
            int nx = x + dx_[dir];
            int ny = y + dy_[dir];

            if(maze.at(nx, ny) != Maze::Cell::WALL)
                continue;
            
            maze.matr_[(nx + x)/2][(ny + y)/2] = Maze::Cell::EMPTY;
            maze.matr_[nx][ny] = Maze::Cell::EMPTY;

            inEdge = true;
            edge.push_back({nx, ny});
    
            if(animated_)
                maze.printAll();
            break;
        }

        if(!inEdge)
            edge.pop_back();
    }
}

void MazeGenerator::generEdgeMaze(int x, int y, Maze & maze) const{
    maze.matr_[x][y] = Maze::Cell::EMPTY;

    std::vector<std::pair<int, int> > edge;
    edge.push_back({x, y});
    std::vector<int> ways = {0, 1, 2, 3};
    
    while(!edge.empty()){
        random_shuffle(ways.begin(), ways.end());
        swap(edge.at(rand()%edge.size()), edge.back());
        
        bool inEdge = false;

        int x = edge.back().first;
        int y = edge.back().second;

        for(int dir : ways){
            int nx = x + dx_[dir];
            int ny = y + dy_[dir];

            if(maze.at(nx, ny) != Maze::Cell::WALL)
                continue;
            
            maze.matr_[(nx + x)/2][(ny + y)/2] = Maze::Cell::EMPTY;
            maze.matr_[nx][ny] = Maze::Cell::EMPTY;

            inEdge = true;
            edge.push_back({nx, ny});
    
            if(animated_)
                maze.printAll();
            break;
        }

        if(!inEdge)
            edge.pop_back();
    }
}

const int MazeGenerator::dx_[] = {0, 2, 0, -2};
const int MazeGenerator::dy_[] = {2, 0, -2, 0};