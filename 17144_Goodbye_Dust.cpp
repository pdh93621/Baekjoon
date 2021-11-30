#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int R, C, T;
int A[50][50];
vector<int> cleaner;
queue<pair<int, pair<int, int>>> dust;
int x_dir[4] = {-1, 0, 1, 0};
int y_dir[4] = {0, 1, 0, -1};

void blow_wind(){
    int cy = cleaner[0];
    for(int i = 1; i < cy; i++) A[cy - i][0] = A[cy - i - 1][0];
    for(int i = 1; i < C; i++) A[0][i - 1] = A[0][i];
    for(int i = 1; i <= cy; i++) A[i - 1][C - 1] = A[i][C - 1];
    for(int i = C - 1; i > 1; i--) A[cy][i] = A[cy][i - 1];
    A[cy][1] = 0;
    cy = cleaner[1];
    for(int j = cy + 1; j < R - 1; j++) A[j][0] = A[j + 1][0];
    for(int j = 1; j < C; j++) A[R - 1][j - 1] = A[R - 1][j];
    for(int j = 1; R - j > cy; j++) A[R - j][C - 1] = A[R - j - 1][C - 1];
    for(int j = C - 1; j > 1; j--) A[cy][j] = A[cy][j - 1];
    A[cy][1] = 0;
}

void diffusion(int x, int y){
    int nx, ny;
    int df = A[x][y] / 5;
    for(int i = 0; i < 4; i++){
        nx = x + x_dir[i];
        ny = y + y_dir[i];
        if(nx >= 0 && ny >= 0 && nx < R && ny < C && A[nx][ny] != -1){
            A[x][y] -= df;
            dust.push({df, {nx, ny}});
        }
    }
}

void final_diff(){
    int x, y, df;
    while(!dust.empty()){
        df = dust.front().first;
        x = dust.front().second.first;
        y = dust.front().second.second;
        dust.pop();
        A[x][y] += df;
    }
}

void total_dust(){
    int result = 0;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++) result += A[i][j];
    }
    cout << result + 2 << endl;
}

void solution(int t){
    if(t == T) {
        total_dust();
        return;
    }
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++) if(A[i][j] >= 5) diffusion(i, j);
    }
    final_diff();
    blow_wind();
    solution(t + 1);
}

int main(){
    cin >> R >> C >> T;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> A[i][j];
            if(A[i][j] == -1) cleaner.push_back(i);
        }
    }

    solution(0);

    return 0;
}