#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int N, M, K;
int map[21][21];
int bonus[21][21];
int dir;
int x_dir[4] = {0, 1, 0, -1};
int y_dir[4] = {1, 0, -1, 0};
int dice[3][3];
int x = 1;
int y = 1;

void get_dir(){
    int bottom = 7 - dice[1][1];
    //cout << bottom << endl;
    if(bottom > map[x][y]) dir = (dir + 1) % 4;
    else if(bottom < map[x][y]) dir = (dir + 3) % 4;
    int nx = x + x_dir[dir];
    int ny = y + y_dir[dir];
    if(nx < 1 || ny < 1 || nx > N || ny > M) dir = (dir + 2) % 4;
}

void move_dice(){
    x += x_dir[dir];
    y += y_dir[dir];
    dice[1 + x_dir[dir]][1 + y_dir[dir]] = dice[1][1];
    dice[1][1] = dice[1 - x_dir[dir]][1 - y_dir[dir]];
    dice[1 - x_dir[dir]][1 - y_dir[dir]] = 7 - dice[1 + x_dir[dir]][1 + y_dir[dir]];
}

int get_bonus(pair<int, int> start){
    if(bonus[start.first][start.second]) return bonus[start.first][start.second];

    int b = 0;
    int num = map[start.first][start.second];
    bool visited[21][21] = {0,};
    int n, m;
    int nn, nm;
    visited[start.first][start.second] = true;
    queue<pair<int, int>> q;
    q.push(start);
    
    while(!q.empty()){
        n = q.front().first;
        m = q.front().second;
        q.pop();
        b++;
        for(int i = 0; i < 4; i++){
            nn = n + x_dir[i];
            nm = m + y_dir[i];
            if(nn > 0 && nm > 0 && nn <= N && nm <= M && !visited[nn][nm] && map[nn][nm] == num){
                visited[nn][nm] = true;
                q.push(make_pair(nn, nm));
            }
        }
    }

    for(int j = 1; j <= N; j++){
        for(int k = 1; k <= M; k++){
            if(visited[j][k]) bonus[j][k] = b;
        }
    }
    return b;
}

int main(){
    int result = 0;

    cin >> N >> M >> K;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> map[i][j];
        }
    }

    dice[0][1] = 2;
    dice[1][0] = 4;
    dice[1][1] = 1;
    dice[1][2] = 3;
    dice[2][1] = 5;

    while(K--){
        move_dice();
        result += map[x][y] * get_bonus(make_pair(x, y));
        get_dir();
    }

    cout << result << endl;

    return 0;
}