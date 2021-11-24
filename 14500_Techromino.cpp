#include <iostream>

using namespace std;

int N, M;
int map[500][500];
int mapx[4];
int mapy[4];
int x_dir[4] = {0, 1};
int y_dir[4] = {1, 0};

bool first_line(int num, int d, int x, int y){
    int nx, ny;
    for(int i = 0; i < num; i++){
        nx = x + i * x_dir[d];
        ny = y + i * y_dir[d];
        if(nx >= N || ny >= M) return false;
        mapx[i] = nx;
        mapy[i] = ny;
    }
    return true;
}

bool second_line(int num, int d, int x, int y, int n){
    if(num == 4) return true;
    int nx, ny;
    for(int i = 0; i < 4 - num; i++){
        nx = x + !x_dir[d] + (n - i) * x_dir[d];
        ny = y + !y_dir[d] + (n - i) * y_dir[d];
        if(nx < 0 || ny < 0 || nx >= N || ny >= M) return false;
        mapx[num + i] = nx;
        mapy[num + i] = ny;
    }
    return true;
}

void look_obj(){
    for(int i = 0; i < 4; i++){
        cout << "(" << mapx[i] << "," << mapy[i] << ")" << " ";
    }
    cout << "\n";
}

int get_score(){
    int score = 0;
    for(int i = 0; i < 4; i++){
        score += map[mapx[i]][mapy[i]];
    }
    //look_obj();
    return score;
}

int matching(int num, int d){
    int result = 0;
    for(int x = 0; x < N; x++){
        for(int y = 0; y < M; y++){
            if(first_line(num, d, x, y)){
                for(int n = 0; n < 3; n++){
                    if(second_line(num, d, x, y, n)) result = max(result, get_score()); 
                }
            }
        }
    }
    return result;
}

int main(){
    int result = 0;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }

    for(int num = 1; num <=4; num++){
        result = max(result, max(matching(num, 0), matching(num, 1)));
    }
    
    cout << result << endl;
}