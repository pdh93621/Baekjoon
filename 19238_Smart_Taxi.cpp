#include <iostream>
#include <queue>
#include <utility>

using namespace std;

typedef struct{
    int x, y, ori_x, ori_y;
    bool visited;
} info;

int N, M;
int fuel;
int x, y;
int map[20][20];
info C[401];

int x_dir[4] = {-1, 0, 0, 1};
int y_dir[4] = {0, 1, -1, 0};

queue<pair<int, int>> visits;

void look_map(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cout << map[i][j] << "\t";
        cout << "\n";
    }
    cout << "\n";
}

void reset_map(bool k){
    int tx, ty;
    while(!visits.empty()){
        tx = visits.front().first;
        ty = visits.front().second;
        map[tx][ty] = 0;
        visits.pop();
    }
    
    if(!k) return;

    for(int i = 1; i <= M; i++){
        if(C[i].visited) continue;
        map[C[i].ori_x][C[i].ori_y] = -i; 
    }
}

int find_c(){
    if(map[x][y] < 0) return 0;

    int nx, ny;
    int tx, ty;
    int leng = 1000;
    queue<pair<int, int>> q;
    pair<int, int> c = {N, N};
    q.push({x, y});
    visits.push({x, y});
    map[x][y] = 1;
    
    while(!q.empty()){
        tx = q.front().first;
        ty = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            nx = tx + x_dir[i];
            ny = ty + y_dir[i];
            if(nx >= 0 && ny >= 0 && nx < N && ny < N && map[nx][ny] <= 0){
                if(map[tx][ty] > leng) break;
                
                if(map[nx][ny] < 0) {
                    c = min({nx, ny}, c);
                    leng = min(map[tx][ty], leng);
                }
                else {
                    map[nx][ny] = map[tx][ty] + 1;
                    q.push({nx, ny});
                    visits.push({nx, ny});
                }
            }
        }
    }

    if(leng > fuel) return -1;

    x = c.first;
    y = c.second;

    return leng;
}

int go_target(){
    int nx, ny;
    int tx, ty;
    int t = -map[x][y];
    C[t].visited = true;
    queue<pair<int, int>> q;
    q.push({x, y});
    visits.push({x, y});
    map[x][y] = 1;

    while(!q.empty()){
        tx = q.front().first;
        ty = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            nx = tx + x_dir[i];
            ny = ty + y_dir[i];
            if(nx >= 0 && ny >= 0 && nx < N && ny < N && map[nx][ny] <= 0) {
                if(nx == C[t].x && ny == C[t].y) {
                    if(map[tx][ty] > fuel) return -1;
                    else {
                        x = nx;
                        y = ny;                        
                        return map[tx][ty];
                    }
                }
                q.push({nx, ny});
                visits.push({nx, ny});
                map[nx][ny] = map[tx][ty] + 1;
            }
        }
    }
    return -1;
}

int main(){
    int f1, f2;
    int cx, cy, tx, ty;
    bool is_poss;
    cin >> N >> M >> fuel;
    int m = M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
            if(map[i][j]) map[i][j] += 500;
        }
    }

    cin >> x >> y;
    x--;
    y--;
    for(int i = 1; i <= M; i++){
        cin >> cx >> cy >> tx >> ty;
        C[i] = {tx - 1, ty - 1, cx - 1, cy - 1, false};
        map[cx - 1][cy - 1] = -i;
    }

    while(m--) {
        f1 = find_c();
        if(f1 >= 0) {
            fuel -= f1;
            reset_map(0);
            f2 = go_target();
            if(f2 >= 0) {
                fuel += f2;
                reset_map(1);
            }
            else {
                fuel = -1;
                break;
            }
        }
        else {
            fuel = -1;
            break;
        }
    }
    //look_map();

    cout << fuel << endl;

    return 0;
}