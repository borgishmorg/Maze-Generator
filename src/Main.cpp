#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <chrono>
#include <thread>
#include <conio.h>

#include "Maze.hpp"
#include "MazeGenerator.hpp"

using namespace std;

/*
void game(){
    printPlayer();
    char c;
    while(true){
        while(!_kbhit());
        c = _getch();
        switch (c){
            case 'w':
                if(px - 1 >= 0 && matr[px - 1][py] == ' ')
                    px -= 1;
                break;
            case 's':
                if(px + 1 <= n && matr[px + 1][py] == ' ')
                    px += 1;
                break;
            case 'a':
                if(py - 1 >= 0 && matr[px][py - 1] == ' ')
                    py -= 1;
                break;
            case 'd':
                if(py + 1 <= m && matr[px][py + 1] == ' ')
                    py += 1;
                break;
            
            default:
                continue;
        }
        printPlayer();
        this_thread::sleep_for(chrono::milliseconds(33));
    }
}
*/
int main(){
    MazeGenerator generator;
    
    generator.setSize(50, 50);
    generator.setPlayerPos(25, 25);
    generator.setType(MazeGenerator::Type::DFS);

    Maze maze = generator.getMaze();

    maze.printAll();
    return 0;
}