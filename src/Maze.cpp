#include "Maze.hpp"

Maze::Maze(int n, int m, int px, int py):
    n_(n), m_(m),
    px_(px), py_(py),
    matr_(n + 1, std::vector<Cell>(m + 1, Cell::WALL)){}

void Maze::movePlayer(Direction dir){
    switch (dir){
        case Direction::UP:
            if(px_ - 1 >= 0 && matr_[px_ - 1][py_] == Cell::EMPTY)
                px_ -= 1;
            break;
        case Direction::DOWN:
            if(px_ + 1 <= n_ && matr_[px_ + 1][py_] == Cell::EMPTY)
                px_ += 1;
            break;
        case Direction::LEFT:
            if(py_ - 1 >= 0 && matr_[px_][py_ - 1] == Cell::EMPTY)
                py_ -= 1;
            break;
        case Direction::RIGHT:
            if(py_ + 1 <= m_ && matr_[px_][py_ + 1] == Cell::EMPTY)
                py_ += 1;
            break;
    }
}

const Maze::Cell Maze::at(int x, int y) const{
    if(x < 0 || y < 0 ||
       x > n_ || y > m_)
        return Cell::NO_TYPE;

    return matr_[x][y];
}

void Maze::printPlayer() const{
    sleep(40);
    system(CLEAR);

    for(int i = px_ - 10; i <= px_ + 10; i++){
        for(int j = py_ - 10; j <=  py_ + 10; j++){
            if(i < 0 || j < 0 || i > n_ || j > m_)
                std::cout << ' ';
            elif(i == px_ && j == py_)
                std::cout << 'P';
            else
                std::cout << matr_[i][j];
        }
        std::cout << '\n';
    }
}

void Maze::printAll() const{
    sleep(40);
    system(CLEAR);
    for(int i = 0; i <= n_; i++){
        for(int j = 0; j <=  m_; j++){
            if(i < 0 || j < 0 || i > n_ || j > m_)
                std::cout << ' ';
            elif(i == px_ && j == py_)
                std::cout << 'P';
            else
                std::cout << matr_[i][j];
        }
        std::cout << '\n';
    }
    std::cout.flush();
}

std::ostream & operator<<(std::ostream & out, Maze::Cell cell){
    switch(cell){
        case Maze::Cell::WALL:{
            out << '#';
            break;
        }
        case Maze::Cell::EMPTY:{
            out << ' ';
            break;
        }
    }
    return out;
}