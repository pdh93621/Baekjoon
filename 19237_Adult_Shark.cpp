#include <iostream>
#include <list>

using namespace std;

typedef struct{
    int x, y;
    int t;
} frag_info;

typedef struct{
    int x, y;
    int o[4][4];
    int dir;
    bool out;
    list<frag_info> f;
} info;

int N, M, k;
int tile[20][20];
int temp_M;

int x_dir[4] = {-1, 1, 0, 0};
int y_dir[4] = {0 ,0, -1, 1};

int T = 0;

info sharks[401];

void look_tile(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cout << tile[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}

int priority(int n){
    int d = sharks[n].dir;
    int nx, ny;
    int temp = -1;
    
    for(int i  = 0; i < 4; i++){
        nx = sharks[n].x + x_dir[sharks[n].o[d][i]];
        ny = sharks[n].y + y_dir[sharks[n].o[d][i]];
        if(nx >= 0 && ny >= 0 && nx < N && ny < N){
            if(!tile[nx][ny]) return sharks[n].o[d][i];
            else if(tile[nx][ny] == n && temp < 0) temp = sharks[n].o[d][i]; 
        }
    }

    return temp;
}

void in_my_way(int x, int y, int i){
    list<frag_info>::iterator iter;
    for(iter = sharks[i].f.begin(); iter != sharks[i].f.end(); iter++){
        if((*iter).x == x && (*iter).y == y) {
            sharks[i].f.erase(iter);
            sharks[i].f.push_back({x, y, T});
            return;
        }
    }
}

void new_area(int x, int y, int i){
    sharks[i].f.push_back({x, y, T});
    tile[x][y] = i;
}

void move(){
    T++;
    int dir;
    //각 상어들의 방향 설정
    for(int i = 1; i <= M; i++){
        if(sharks[i].out) continue;
        dir = priority(i);
        sharks[i].dir = dir;
        sharks[i].x += x_dir[dir];
        sharks[i].y += y_dir[dir];
    }

    //각 상어 이동
    int temp;
    for(int i = 1; i <= M; i++){
        if(sharks[i].out) continue;
        temp = tile[sharks[i].x][sharks[i].y];
        if(temp == 0) new_area(sharks[i].x, sharks[i].y, i);
        else if(temp == i) in_my_way(sharks[i].x, sharks[i].y, i);
        else {
            sharks[i].out = true;
            temp_M--;
        }
    }

    
    for(int i = 1; i <= M; i++){
        if(sharks[i].f.empty()) continue;
        if(T - sharks[i].f.front().t >= k) {
            tile[sharks[i].f.front().x][sharks[i].f.front().y] = 0;
            sharks[i].f.pop_front();
        }
    }
    //look_tile();
}

int main(){
    int temp;
    cin >> N >> M >> k;
    temp_M = M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> tile[i][j];
            if(tile[i][j]){
                sharks[tile[i][j]].x = i;
                sharks[tile[i][j]].y = j;
                sharks[tile[i][j]].f.push_back({i, j, 0});
            }
        }
    }

    for(int i = 1; i <= M; i++){
        cin >> sharks[i].dir;
        sharks[i].dir--;
    }

    for(int i = 1; i <= M; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                cin >> temp;
                sharks[i].o[j][k] = --temp;
            }
        }
    }

    while(T <= 1000 && temp_M > 1) move();       

    if(T > 1000) cout << -1 << endl;
    else cout << T << endl;

    return 0;
}