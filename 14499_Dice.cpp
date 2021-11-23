#include <iostream>

using namespace std;

int N, M;
int x, y;
int K;
int map[20][20];
int dice[3][3];
int bottom;

int x_dir[4] = {0, 0, -1, 1};
int y_dir[4] = {1, -1, 0, 0};

void move_dice(int dir){
    dir--;
    int nx = x + x_dir[dir];
    int ny = y + y_dir[dir];
    
    if(nx < 0 || ny < 0 || nx >= N || ny >= M) return;
    x = nx;
    y = ny;
    int num = map[x][y];
    int temp = dice[1 + x_dir[dir]][1 + y_dir[dir]]; 
    dice[1 + x_dir[dir]][1 + y_dir[dir]] = dice[1][1];
    dice[1][1] = dice[1 - x_dir[dir]][1 - y_dir[dir]];
    dice[1 - x_dir[dir]][1 - y_dir[dir]] = bottom;

    if(num){
        bottom = num;
        map[x][y] = 0;
    }
    else{
        bottom = temp;
        map[x][y] = bottom;
    }

    cout << dice[1][1] << "\n";
}

int main(){
    int dir;
    cin >> N >> M;
    cin >> x >> y;
    cin >> K;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }

    while(K--){
        cin >> dir;
        move_dice(dir);
    }

    return 0;
}