#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int N, M;
int lab[8][8];
int visited[8][8];
int base[8][8];
int x_dir[4] = {-1, 0, 0, 1};
int y_dir[4] = {0, 1, -1, 0};
int poles_x[3];
int poles_y[3];
queue<pair<int, int>> virus;
queue<pair<int, int>> origin;
int result;

void look_lab(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << lab[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int get_result(){
    int temp = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!lab[i][j]) temp++;
        }
    }
    return temp;
}

void reset_lab(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            lab[i][j] = base[i][j];
        }
    }
}

void spread(){
    virus = origin;
    int nx;
    int ny;
    while(!virus.empty()){
        int x = virus.front().first;
        int y = virus.front().second;
        virus.pop();
        for(int i = 0; i < 4; i++){
            nx = x + x_dir[i];
            ny = y + y_dir[i];
            if(nx >= 0 && nx < N && ny >= 0 && ny < M && !lab[nx][ny]){
                lab[nx][ny] = 2;
                virus.push(make_pair(nx, ny));
            }
        }
    }    
}

void make_poles(){
    for(int i = 0; i < 3; i++){
        lab[poles_x[i]][poles_y[i]] = 1;
    }
}

void solution(int k, pair<int, int> p){
    if(k == 3){
        make_poles();
        spread();
        result = max(result, get_result());
        reset_lab();
        return;
    }

    pair<int, int> temp;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!lab[i][j]){
                temp = make_pair(i, j);
                if(temp > p){
                    poles_x[k] = i;
                    poles_y[k] = j;
                    solution(k + 1, temp);
                }
            }
        }
    }
}

int main(){
    int temp;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> temp;
            lab[i][j] = temp;
            base[i][j] = temp;
            if(temp == 2) origin.push(make_pair(i, j));
        }
    }

    solution(0, make_pair(-1, -1));

    cout << result << endl;

    return 0;
}