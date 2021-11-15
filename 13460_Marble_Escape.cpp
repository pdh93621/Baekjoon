#include <iostream>
#include <string>

using namespace std;

int N, M;
char board[10][10];
int visited[10][10];

int x_dir[4] = {1, -1, 0, 0};
int y_dir[4] = {0, 0, 1, -1};

int main(){

    int red_x, red_y;
    int blue_x, blue_y;

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        string temp;
        cin >> temp;
        for(int j = 0; j < M; j++){
            board[i][j] = temp[j];
            if(temp[j] == 'R'){
                red_x = i;
                red_y = j;
            }
            else if(temp[j] == 'B'){
                blue_x = i;
                blue_y = j;
            }
        }
    }

    return 0;
}