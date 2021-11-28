#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int N, L, R;
int land[50][50];

int x_dir[4] = {-1, 0, 1, 0};
int y_dir[4] = {0, 1, 0, -1};

int open_border(int x, int y, bool visited[][50]){
    queue<pair<int, int>> q;
    queue<pair<int, int>> q2;
    bool t[50][50] = {0,};
    int nx, ny;
    int total_pop = 0;
    int total_nat = 0;
    int diff_pop;
    int result_pop;
    q.push(make_pair(x, y));
    
    visited[x][y] = true;
    t[x][y] = true;

    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q2.push(make_pair(x, y));
        q.pop();
        total_nat++;
        total_pop += land[x][y];
        for(int i = 0; i < 4; i++){
            nx = x + x_dir[i];
            ny = y + y_dir[i];
            diff_pop = abs(land[nx][ny] - land[x][y]);
            if(nx >= 0 && ny >= 0 && nx < N && ny < N && !visited[nx][ny]){
                if(diff_pop >= L && diff_pop <= R){
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = true;
                    t[nx][ny] = true;
                }
            }
        }
    }
    result_pop = total_pop / total_nat;
    while(!q2.empty()){
        x = q2.front().first;
        y = q2.front().second;
        land[x][y] = result_pop;
        q2.pop();
    }
    return total_nat;
}

int get_day(int n){
    bool visited[50][50] = {0,};
    bool ismove = false;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) if(!visited[i][j] && open_border(i, j, visited) > 1) ismove = true; 
    }
    if(ismove) return get_day(n + 1) + 1;
    else return 0;
}

int main(){
    cin >> N >> L >> R;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cin >> land[i][j];
    }
    cout << get_day(0) << endl;
    return 0;
}