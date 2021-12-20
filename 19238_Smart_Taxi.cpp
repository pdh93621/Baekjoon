#include <iostream>

using namespace std;

typedef struct{
    int x, y;
} info;

int N, M;
int fuel;
int x, y;

int map[20][20];
info C[401];

int main(){
    int cx, cy, tx, ty;
    cin >> N >> M >> fuel;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cin >> map[i][j];
    }
    cin >> x >> y;
    x--;
    y--;
    for(int i = 1; i <= M; i++){
        cin >> cx >> cy >> tx >> ty;
        C[i] = {tx - 1, ty - 1};
        map[cx - 1][cy - 1] = -i;
    }

    return 0;
}