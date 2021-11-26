#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;
int N, M;
int office[8][8];
int original[8][8];
int cam_num;
int cam_mode[5] = {4, 2, 4, 4, 1};
int cam_dir[8];
int x_dir[4] = {0, 1, 0, -1};
int y_dir[4] = {1, 0, -1, 0};
queue<int> directions;
vector<pair<int, int>> cam_loc;
int result = 64;

void add_dirs(int kind, int dir){
    switch (kind)
    {
    case 1:
        directions.push(dir);
        break;
    case 2:
        directions.push(dir);
        directions.push(dir + 2);
        break;
    case 3:
        directions.push(dir);
        directions.push((dir + 1) % 4);
        break;
    case 4:
        for(int i = 0; i < 4; i++) if(i != dir) directions.push(i);
        break;

    default:
        for(int i = 0; i < 4; i++) directions.push(i);
        break;
    }
}

void reset_office(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) office[i][j] = original[i][j];
    }
}

int get_score(){
    int num_zero = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) if(!office[i][j]) num_zero++;
    }
    return num_zero;
}

void can_see(int x, int y, int dir){
    int nx, ny;
    int n = 1;
    while(n){
        nx = x + n * x_dir[dir];
        ny = y + n * y_dir[dir];
        if(nx < 0 || ny < 0 || nx >= N || ny >= M || office[nx][ny] == 6) break;
        else if(!office[nx][ny]) office[nx][ny] = 7;
        n++;
    }
}

void dfs(int num){
    int x, y;
    if(num == cam_num){
        int kind, dir;
        for(int i = 0; i < num; i++){
            x = cam_loc[i].first;
            y = cam_loc[i].second;
            kind = original[x][y];
            dir = cam_dir[i];
            add_dirs(kind, dir);
            while(!directions.empty()){
                can_see(x, y, directions.front());
                directions.pop();
            }
        }
        result = min(result, get_score());
        reset_office();
        return;
    }    
    for(int i = 0; i < 4; i++){
        x = cam_loc[num].first;
        y = cam_loc[num].second;
        if(i >= cam_mode[original[x][y] - 1]) return;
        cam_dir[num] = i;
        dfs(num + 1);
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> office[i][j];
            original[i][j] = office[i][j];
            if(office[i][j] && office[i][j] != 6) cam_loc.push_back(make_pair(i, j));
        }
    }
    cam_num = cam_loc.size();
    
    dfs(0);

    cout << result << endl;

    return 0;
}