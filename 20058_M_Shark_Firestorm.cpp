#include <iostream>
#include <queue>
#include <cmath>
#include <utility>

using namespace std;

int N, Q;

int A[64][64];
bool visited[64][64];

int x_dir[4] = {-1, 0, 1, 0};
int y_dir[4] = {0, 1, 0, -1};

int ice;
queue<int> temp;
queue<pair<int, int>> q;
queue<pair<int, int>> qq;

void rotation(int dx, int dy, int l){
    
    dx *= l;
    dy *= l;
    for(int i = dx; i < dx + l; i++){
        for(int j = dy; j < dy + l; j++) temp.push(A[i][j]);
    }
    
    for(int j = dy + l - 1; j >= dy; j--){
        for(int i = dx; i < dx + l; i++) {
            A[i][j] = temp.front();
            temp.pop();
        }
    }
}

void rotation_all(int l){
    l = (int)pow(2, l);
    int num = N / l;
    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++) rotation(i, j, l);
    }
}

bool melt(int x, int y) {
    int num = 0;
    int nx, ny;
    for(int i = 0; i < 4; i++) {
        nx = x + x_dir[i];
        ny = y + y_dir[i];
        if(nx >= 0 && ny >=0 && nx < N && ny < N && A[nx][ny]) num++;
    }

    return (num < 3);
}

void melt_all() {
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) if(A[i][j] && melt(i, j)) q.push({i, j});
    }

    while(!q.empty()) {
        A[q.front().first][q.front().second]--;
        q.pop();
    }
}

int bfs(int x, int y) {
    
    int nx, ny;
    int mass = 0;
    qq.push({x, y});
    visited[x][y] = true;

    while(!qq.empty()) {
        x = qq.front().first;
        y = qq.front().second;
        mass++;
        ice += A[x][y];
        qq.pop();

        for(int i = 0; i < 4; i++) {
            nx = x + x_dir[i];
            ny = y + y_dir[i];
            if(nx >= 0 && ny >= 0 && nx < N && ny < N && !visited[nx][ny] && A[nx][ny]) {
                qq.push({nx, ny});
                visited[nx][ny] = true;
            }
        }   
    }

    return mass;
}

int main(){
    cin >> N >> Q;
    N = (int)pow(2, N);
    int l;
    int mass = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cin >> A[i][j];
    }

    while(Q--) {
        cin >> l;
        rotation_all(l);
        melt_all();
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(!visited[i][j] && A[i][j]) mass = max(bfs(i, j), mass);
        }
    }

    cout << ice << endl;
    cout << mass << endl;

    return 0;
}