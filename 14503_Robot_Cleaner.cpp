#include <iostream>

using namespace std;

int area[50][50];
int N, M;
int r, c, d;

int x_dir[4] = {-1,0,1,0};
int y_dir[4] = {0,1,0,-1};
int result = 0;

void look_area(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << area[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool searching(){
    for(int i = 0; i < 4; i++){
        d = (--d + 4) % 4;
        if(!area[r + x_dir[d]][c + y_dir[d]]){
            r += x_dir[d];
            c += y_dir[d];
            return true;
        }
    }
    return false;
}

void bfs(){
    if(area[r][c] == 1) return;
    else if(area[r][c] == 0) result++;
    area[r][c] = 2;
    if(!searching()){
        int temp = (d + 2) % 4;
        r += x_dir[temp];
        c += y_dir[temp];
    }
    bfs();
}

int main(){
    cin >> N >> M;
    cin >> r >> c >> d;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> area[i][j];
        }
    }

    bfs();

    cout << result << endl;

    return 0;
}