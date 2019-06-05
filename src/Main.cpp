#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <chrono>
#include <thread>
#include <conio.h>

#define elif else if

#define CLEAR "clear"

using namespace std;

int n = 70, m = 260; // maze size
int dx[] = {0, 2, 0, -2};
int dy[] = {2, 0, -2, 0};

int px = 1, py = 1;

char matr[1000][1000]; // maze

void printPlayer(){
    system(CLEAR);
    for(int i = px - 10; i <= px + 10; i++){
        for(int j = py - 10; j <=  py + 10; j++){
            if(i < 0 || j < 0 || i > n || j > m)
                cout << ' ';
            elif(i == px && j == py)
                cout << 'P';
            else
                cout << matr[i][j];
        }
        cout << '\n';
    }
}

void printAll(){
    this_thread::sleep_for(chrono::milliseconds(40));
    system(CLEAR);
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <=  m; j++){
            if(i < 0 || j < 0 || i > n || j > m)
                cout << ' ';
            elif(i == px && j == py)
                cout << 'P';
            else
                cout << matr[i][j];
        }
        cout << '\n';
    }
    cout.flush();
}

void init(){
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= m; j++)
            matr[i][j] = '#';
}

void generMaze(int x, int y){
    matr[x][y] = ' ';

    vector<int> ways = {0, 1, 2, 3};
    while(!ways.empty()){
        int p = rand()%ways.size();
        int dir = ways[p];
        ways.erase(ways.begin() + p);

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(nx < 0 || ny < 0 ||
           nx > n || ny > m ||
           matr[nx][ny] == ' ')
            continue;
        
        matr[(nx + x)/2][(ny + y)/2] = ' ';
        printAll();
        generMaze(nx, ny);
    }
}


int main(){
    cout.tie(0);
    srand(time(NULL));
    init();
    generMaze(1, 1);
    /*printPlayer();
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
    }*/
    return 0;
}