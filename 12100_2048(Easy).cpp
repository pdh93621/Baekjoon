#include <iostream>
#include <stack>
#include <utility>

using namespace std;

int board[20][20];
int N;

int x_dir[4] = {-1, 0, 0, 1};
int y_dir[4] = {0, -1, 1, 0};

void move(int dir){
    stack<pair<int, bool>> temp;
    
}

int main(){

    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }

    return 0;
}