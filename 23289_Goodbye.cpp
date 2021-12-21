#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

typedef struct{
    int x, y, change;
}info;

int R, C, K;
int choco;

int x_dir[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int y_dir[8] = {0, 1, 1, 1, 0, -1, -1, -1};

vector<pair<int, int>> check;
vector<vector<pair<int, int>>> heater(4);

int room[20][20][4];
int degree[20][20];
int forq[20][20];


queue<pair<int, int>> visited;
queue<info> temp_change;

void look_degree(){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++) cout << degree[i][j] << "\t";
        cout << "\n";
    }
    cout << "\n";
}

int d2dir(int d){
    switch (d)
    {
    case 0:
        return 2;
    case 1:
        return 6;
    case 2:
        return 0;
    case 3:
        return 4;
    }
}

void work_heater(int d, int n){
    queue<pair<int, int>> q;    
    int x = heater[d][n].first;
    int y = heater[d][n].second;
    int dir = d2dir(d);
    int nx, ny;

    x += x_dir[dir];
    y += y_dir[dir];
    
    q.push({x, y});
    visited.push({x, y});
    forq[x][y] = 5;
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        degree[x][y] += forq[x][y];
        q.pop();
        for(int i = -1; i <= 1; i++){
            if(forq[x][y] == 1) break;
            nx = x + x_dir[(dir + i + 8) % 8];
            ny = y + y_dir[(dir + i + 8) % 8];
            if(nx >= 0 && ny >= 0 && nx < R && ny < C && !forq[nx][ny] && !room[x][y][(dir / 2 + i + 4) % 4] && !room[nx][ny][(dir / 2 + 2) % 4]) {
                q.push({nx, ny});
                visited.push({nx, ny});
                forq[nx][ny] = forq[x][y] - 1;
            }
        }
    }
    
    while(!visited.empty()){
        nx = visited.front().first;
        ny = visited.front().second;
        forq[nx][ny] = 0;
        visited.pop();
    }
}

void work_all(){
    for(int d = 0; d < 4; d++){
        for(int n = 0; n < heater[d].size(); n++) work_heater(d, n);
    }
}

void down_degree(){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(i == 0 || i == R - 1 || j == 0 || j == C - 1) if(degree[i][j]) degree[i][j]--;
        }
    }
}

void control_deg(){
    int nr, nc;
    int t;
    info temp;
    for(int r = 0; r < R; r++){
        for(int c = 0; c < C; c++){
            for(int i = 0; i < 2; i++){
                if(room[r][c][i]) continue;
                nr = r + x_dir[2 * i];
                nc = c + y_dir[2 * i];
                if(nr >= 0 && nc >= 0 && nr < R && nc < C){
                    t = (degree[r][c] - degree[nr][nc]) / 4;
                    if(!t) continue;
                    temp_change.push({r, c, -t});
                    temp_change.push({nr, nc, t});
                }
            }
        }
    }

    while(!temp_change.empty()){
        temp = temp_change.front();
        degree[temp.x][temp.y] += temp.change;
        temp_change.pop();
    }
}

bool check_d(){
    for(auto c: check) if(degree[c.first][c.second] < K) return false;
    return true;
}

int main(){
    int temp;
    int W;
    int x, y;
    bool t;
    cin >> R >> C >> K;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> temp;
            if(temp == 5) check.push_back({i, j});
            else if(temp) heater[temp - 1].push_back({i, j});
        }
    }

    cin >> W;
    while(W--){
        cin >> x >> y >> t;
        x--;
        y--;
        room[x][y][t] = true;
        room[x - !t][y + t][2 + t] = true;
    }
    
    while(choco++ < 100){
        work_all();
        control_deg();
        down_degree();
        if(check_d()) break;
    }

    //look_degree();
    cout << choco << endl;
    return 0;
}