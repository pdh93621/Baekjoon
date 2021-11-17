#include <iostream>

using namespace std;

int board[20][20];

int x_dir[4] = {-1, 0, 0, 1};
int y_dir[4] = {0, -1, 1, 0};

int main(){

    int N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }

    return 0;
}