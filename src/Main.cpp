#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int n = 40, m = 80; // maze size
int dx[] = {0, 2, 0, -2};
int dy[] = {2, 0, -2, 0};

char matr[100][100]; // maze

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
        generMaze(nx, ny);
    }
}

void print(){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++)
            cout << matr[i][j];
        cout << '\n';
    }
}

int main(){
    srand(time(NULL));
    init();
    generMaze(1, 1);
    print();
    return 0;
}