#include <iostream>
#include <queue>
#include <utility>
#include <cmath>

using namespace std;

typedef struct{
    int ID;
    int empty;
} info;

int N;

queue<int> ID;
int favorite[401][4];
info room[20][20];

int x_dir[4] = {-1, 0, 0, 1};
int y_dir[4] = {0, -1, 1, 0};

void look_room(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cout << room[i][j].ID << " ";
        cout << "\n";
    }
    cout << "\n";
}

int get_score(){
    int temp;
    int nx, ny;
    int result = 0;
    for(int x = 0; x < N; x++){
        for(int y = 0; y < N; y++){
            temp = 0;
            for(int i = 0; i < 4; i++){
                nx = x + x_dir[i];
                ny = y + y_dir[i];
                if(nx >= 0 && ny >= 0 && nx < N && ny < N){
                    for(auto f: favorite[room[x][y].ID]){
                        if(room[nx][ny].ID == f) {
                            temp++;
                            break;
                        }
                    }
                }
            }
            if(temp) result += pow(10, temp - 1);
        } 
    }
    return result;
}

void put_st(int x, int y){
    int nx, ny;
    int id = ID.front();
    ID.pop();
    room[x][y].ID = id;
    for(int i = 0; i < 4; i++){
        nx = x + x_dir[i];
        ny = y + y_dir[i];
        if(nx >= 0 && ny >= 0 && nx < N && ny < N) room[nx][ny].empty--;
    }
}

void choose_sit(){
    int id = ID.front();
    int nx, ny;
    pair<int, int> best = {-1, -1};
    int temp;
    pair<int, int> now;
    pair<int, int> result;
    for(int x = 0; x < N; x++){
        for(int y = 0; y < N; y++){
            if(!room[x][y].ID){
                //호감있는 친구 수 찾기
                temp = 0;
                for(int i = 0; i < 4; i++){
                    nx = x + x_dir[i];
                    ny = y + y_dir[i];
                    if(nx >= 0 && ny >= 0 && nx < N && ny < N && room[nx][ny].ID){
                        for(auto s: favorite[id]) {
                            if(s == room[nx][ny].ID){
                                temp++;
                                break;
                            }
                        }
                    }
                }

                now = {temp, room[x][y].empty};
                if(best < now) {
                    result = {x, y};
                    best = now;
                }
            }
        }
    }
    put_st(result.first, result.second);
}

int main(){
    cin >> N;
    int id;
    for(int i = 1; i <= N * N; i++){
        cin >> id;
        ID.push(id);
        for(int j = 0; j < 4; j++) cin >> favorite[id][j];
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) room[i][j].empty = 4 - (i == 0 || i == N - 1) - (j == 0 || j == N - 1);
    }

    id = ID.front();
    ID.pop();
    room[1][1].ID = id;
    for(int i = 0; i < 4; i++) room[1 + x_dir[i]][1 + y_dir[i]].empty--;

    while(!ID.empty()) choose_sit();

    // look_room();
    cout << get_score() << endl;

    return 0;
}