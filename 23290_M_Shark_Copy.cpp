#include <iostream>
#include <queue>
#include <utility>

using namespace std;

typedef struct{
    int x, y, t;
} sinfo;

typedef struct{
    int fx, fy, d;
} finfo;

typedef struct{
    int num;
    queue<int> d;
} minfo;

int M, S;
int sx, sy;

int x_dir[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int y_dir[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int sx_dir[4] = {-1, 0, 1, 0};
int sy_dir[4] = {0, -1, 0, 1};

queue<finfo> fish;
queue<finfo> fcopy;
queue<sinfo> smell; 
queue<pair<int, int>> location;

minfo m[16][16];

pair<int, int> moves[4];
pair<int, int> best[4];
int bscore;
int s = 1;

void move_fish(finfo f){
    int nx, ny, nd;
    for(int i = 0; i < 8; i++){
        nd = (f.d + 7 * i) % 8;
        nx = f.fx + x_dir[nd];
        ny = f.fy + y_dir[nd];
        if(nx >= 0 && ny >= 0 && nx < 4 && ny < 4 && !m[nx][ny].num){
            if(m[nx][ny].d.empty()) location.push({nx, ny});
            m[nx][ny].d.push(nd);
            return; 
        }
    }
    if(m[f.fx][f.fy].d.empty()) location.push({f.fx, f.fy});
    m[f.fx][f.fy].d.push(f.d);
}

void copy7move(){
    finfo f;
    while(!fish.empty()){
        f = fish.front();
        fish.pop();
        fcopy.push(f);
        move_fish(f);
    }
}

void move_shark(int n, int score){
    if(n == 4) {
        if(score > bscore){
            for(int i = 0; i < 4; i++) best[i] = moves[i];
        }
        return;
    }
    int nx, ny;
    for(int i = 0; i < 4; i++){
        nx = moves[n - 1].first + sx_dir[i];
        ny = moves[n - 1].second + sy_dir[i];

        if(nx >= 0 && ny >= 0 && nx < 4 && ny < 4) {
            if(n >= 2) if(moves[n - 2] == make_pair(nx, ny)) continue;

            moves[n] = {nx, ny};
            move_shark(n + 1, score + m[nx][ny].d.size());
        }
    }
}

void move7smell(){
    moves[0] = {sx, sy};
    m[sx][sy].num = 0;
    move_shark(0, m[sx][sy].d.size());
    bscore = 0;
    for(auto b: best){
        if(m[b.first][b.second].d.empty()) continue;
        m[b.first][b.second].num = s;
        smell.push({b.first, b.second, s});
        while(!m[b.first][b.second].d.empty()) m[b.first][b.second].d.pop();
    }
    sx = best[3].first;
    sy = best[3].second;
    m[sx][sy].num = -1;
    
    while(!smell.empty()){
        if(s - smell.front().t >= 2) {
            if(m[smell.front().x][smell.front().y].num == smell.front().t) m[smell.front().x][smell.front().y] = 0;
            smell.pop(); 
        }
        else break;
    }
}

void add_copy(){
    pair<int, int> temp;
    int temp2;
    while(!location.empty()){
        temp = location.front();
        location.pop();
        while(!m[temp.first][temp.second].d.empty()){
            temp2 = m[temp.first][temp.second].d.front();
            m[temp.first][temp.second].d.pop();
            fish.push({temp.first, temp.second, temp2});
        }
    }

    while(!fcopy.empty()){
        fish.push(fcopy.front());
        fcopy.pop();
    }
}

int main(){
    int fx, fy, d;
    cin >> M >> S;
    
    while(M--){
        cin >> fx >> fy >> d;
        fish.push({fx - 1, fy - 1, d - 1});
    }
    
    cin >> sx >> sy;
    sx--;
    sy--;
    m[sx][sy].num = -1;

    while(S--){
        copy7move();
        move7smell();
        add_copy();
        s++;
    }

    cout << fish.size() << endl;
    return 0;
}