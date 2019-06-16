#include "Maze.hpp"

Maze::Maze(int n, int m, int px, int py):
    n_(n), m_(m),
    px_(px), py_(py){
    for(int i = 0; i <= n_; i++)
        for(int j = 0; j <= m_; j++)
            matr_[i][j] = '#';
}

void Maze::movePlayer(Direction dir){
    switch (dir){
        case Direction::UP:
            if(px_ - 1 >= 0 && matr_[px_ - 1][py_] == ' ')
                px_ -= 1;
            break;
        case Direction::DOWN:
            if(px_ + 1 <= n_ && matr_[px_ + 1][py_] == ' ')
                px_ += 1;
            break;
        case Direction::LEFT:
            if(py_ - 1 >= 0 && matr_[px_][py_ - 1] == ' ')
                py_ -= 1;
            break;
        case Direction::RIGHT:
            if(py_ + 1 <= m_ && matr_[px_][py_ + 1] == ' ')
                py_ += 1;
            break;
    }
}

void Maze::printPlayer() const{
    sleep(40);
    std::cout.tie(0);
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
    std::cout.tie(0);
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