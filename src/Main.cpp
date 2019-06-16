#include <conio.h>

#include "Direction.hpp"
#include "Maze.hpp"
#include "MazeGenerator.hpp"

using namespace std;

void play(Maze & maze){
    maze.printPlayer();
    char c;
    while(true){
        while(!_kbhit());
        c = _getch();
    
        try{
            maze.movePlayer(charToDirection(c));
        }catch(...){};

        maze.printPlayer();
    }
}

int main(){
    MazeGenerator generator;

    generator.setSize(50, 50);
    generator.setPlayerPos(25, 25);
    generator.setType(MazeGenerator::Type::BFS);
    generator.setAnimation(true);

    Maze maze = generator.getMaze();

    maze.printAll();
    //play(maze);
    return 0;
}