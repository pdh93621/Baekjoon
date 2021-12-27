#include <iostream>
#include <queue>
#include <utility>

using namespace std;

typedef struct{
    int x, y, score, num0;
} info;

int N, M;
int grid[20][20];

int x_dir[4] = {-1, 0, 1, 0};
int y_dir[4] = {0, 1, 0, -1};

queue<pair<int, int>> zeros;

int sx;
int sy;
int score;

void look_grid() {
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cout << grid[i][j] << "\t";
        cout << "\n";
    }
    cout << "\n";
}

info bfs(int x, int y, bool visited[][20]) {
    info f = {x, y, 0, 0};
    int nx, ny;
    int k = grid[x][y];
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        f.score++;

        for(int i = 0; i < 4; i++) {
            nx = x + x_dir[i];
            ny = y + y_dir[i];
            if(nx >= 0 && ny >= 0 && nx < N && ny < N && !visited[nx][ny] && (grid[nx][ny] == k || !grid[nx][ny])) {
                visited[nx][ny] = true;
                q.push({nx, ny});
                if(!grid[nx][ny]) zeros.push({nx, ny});
            }
        }
    }

    f.num0 = zeros.size();
    while(!zeros.empty()) {
        visited[zeros.front().first][zeros.front().second] = false;
        zeros.pop();
    }

    return f;
}

bool choose_group() {
    info group = {-1, -1, 0, 0};
    info temp;
    bool visited[20][20];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(!visited[i][j] && grid[i][j] > 0 && grid[i][j] < 6) {
                temp = bfs(i, j, visited);
                if(temp.score >= 2) {
                    if(temp.score > group.score) group = temp;
                    else if(temp.score == group.score) {
                        if(temp.num0 >= group.num0) group = temp;
                    }
                }
            }
        }
    }

    if(group.score >= 2) {
        sx = group.x;
        sy = group.y;
        score += group.score * group.score;
    }

    //cout << sx << sy << " " << score << endl;
    return group.score;
}

void delete_group() {
    bool v[20][20] = {0,};
    int x, y, nx, ny;
    int k = grid[sx][sy];
    queue<pair<int, int>> q;
    q.push({sx, sy});
    v[sx][sy] = true;

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        grid[x][y] = 6;
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            nx = x + x_dir[i];
            ny = y + y_dir[i];
            if(nx >= 0 && ny >= 0 && nx < N && ny < N && !v[nx][ny] && (grid[nx][ny] == k || !grid[nx][ny])) {
                q.push({nx, ny});
                v[nx][ny] = true;
            }
        }
    }
}

void gravity() {
    queue<int> temp;
    int num6;
    int num;

    for(int j = 0; j < N; j++) {
        for(int i = N - 1; i >= 0; i--) temp.push(grid[i][j]);
        num = 0;
        num6 = 0;
        while(num++ != N) {
            if(temp.front() >= 0 && temp.front() < 6) {
                temp.push(temp.front());
                temp.pop();
            }
            else if(temp.front() == 6) {
                num6++;
                temp.pop();
            }
            else if(temp.front() == -1) {
                while(num6--) temp.push(6);
                temp.push(-1);
                temp.pop();
                num6 = 0;
            }
        }
        if(num6 > 0) while(num6--) temp.push(6);

        for(int i = N - 1; i >= 0; i--) {
            grid[i][j] = temp.front();
            temp.pop();
        }
    }

}

void rotate() {
    queue<int> q;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) q.push(grid[i][j]);
    }

    for(int j = 0; j < N; j++) {
        for(int i = N - 1; i >= 0; i--) {
            grid[i][j] = q.front();
            q.pop();
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cin >> grid[i][j];
    }

    while(choose_group()) {
        delete_group();
        gravity();
        rotate();
        gravity();
        //look_grid();
    }

    cout << score << endl;

    return 0;
}