#include <iostream>

using namespace std;

int N;
int A[499][499];

int x_dir[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int y_dir[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int percents[2][8] = {{0, 10, 7, 1, 0, 1, 7, 10}, {5, 0, 2, 0, 0, 0, 2, 0}};
int dir = 6;
int r;
int c;
int blow_total;

void look_A(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cout << A[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}

void move_sand(){
    int nr, nc, temp_d, temp_y;
    r += x_dir[dir];
    c += y_dir[dir];    
    int total = A[r][c];   
    for(int i = 0; i < 8; i++){
        temp_d = (dir + i) % 8;
        for(int j = 1; j <= 2; j++){
            temp_y = percents[j - 1][i] * A[r][c] / 100;
            if(!temp_y) continue;
            total -= temp_y;
            nr = r + j * x_dir[temp_d];
            nc = c + j * y_dir[temp_d];
            if(nr >= 0 && nc >= 0 && nr < N && nc < N) A[nr][nc] += temp_y;
            else blow_total += temp_y;
        }
    }
    A[r][c] = 0;
    nr = r + x_dir[dir];
    nc = c + y_dir[dir];
    if(nr >= 0 && nc >= 0 && nr < N && nc < N) A[nr][nc] += total;
    else blow_total += total;
}

void dotdot(int num){
    r += x_dir[dir];
    c += y_dir[dir];
    A[r][c] = num;
}

bool tornado(int num){
    for(int i = 0; i < num; i++){
        move_sand();
        //cout << num << endl;
        //look_A();
        //dotdot(num);
        if(!r && !c) return false;
    }
    dir = (dir + 6) % 8;
    return true;
}

int main(){
    cin >> N;
    int num = 0;
    r = N / 2;
    c = N / 2;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cin >> A[i][j];
    }

    while(tornado(num++ / 2 + 1));

    //look_A();

    cout << blow_total << endl;
    return 0;
}