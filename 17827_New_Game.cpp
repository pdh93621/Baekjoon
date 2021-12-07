#include <iostream>

using namespace std;

typedef struct {
    int row;
    int col;
    int dir;
    int num;
}info;

int N, K;
int board[14][14];
int unit_tower[14][14][5];

int r_dir[4] = {0, 0, -1, 1};
int c_dir[4] = {1, -1, 0, 0};
info units[11];

int height(int r, int c){
    int h = 0;
    while(unit_tower[r][c][h]) h++;
    return h - 1;
}

void look_units(){
    for(int i = 1; i <= K; i++) cout << units[i].row << " " << units[i].col << " " << units[i].dir << " " << units[i].num << endl;
    cout << endl;
}

bool move(int u, bool is_move){
    int c = units[u].col;
    int r = units[u].row;
    int d = units[u].dir;
    int n = units[u].num;
    int nr = r + r_dir[d];
    int nc = c + c_dir[d];
    int bd = board[nr][nc];
    int h1, h2;
    int temp;
    int a;

    if(bd == 2){
        if(is_move) return true;
        if(d < 2) units[u].dir = 1 - d;
        else units[u].dir = 5 - d;
        return move(u, true);
    }
    else{
        h1 = height(r, c);
        if(h1 >= 3) return false;

        h2 = height(nr, nc) + 1;
        
        while(h1 >= n){
            if(h2 >= 3) return false;
            if(bd) a = h1;
            else a = n;

            temp = unit_tower[r][c][a];
            unit_tower[r][c][a] = 0;
            unit_tower[nr][nc][h2] = temp;            
            units[temp] = {nr, nc, units[temp].dir, h2};
            h2++;

            if(bd) h1--;
            else n++;
        }
    }

    return true;
}

int timego(int n){
    if(n > 1000) return -1;

    for(int i = 1; i <= K; i++) if(!move(i, false)) return n;

    //if(n < 5) look_units();
    return timego(n + 1);
}

int main(){
    info temp;
    cin >> N >> K;
    for(int i = 0; i <= N + 1; i++){
        for(int j = 0; j <= N + 1; j++){
            if(i == 0 || j == 0 || i == N + 1 || j == N + 1) board[i][j] = 2;
            else cin >> board[i][j];
        }
    }

    for(int i = 1; i <= K; i++){
        cin >> temp.row >> temp.col >> temp.dir;
        temp.dir--;
        temp.num = 0;
        units[i] = temp;
        unit_tower[units[i].row][units[i].col][units[i].num] = i;
    }
    
    cout << timego(1) << endl;
    //look_units();
    return 0;
}