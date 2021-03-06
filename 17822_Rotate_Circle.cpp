#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int N, M, T;
int circle[51][51];
int r_dir[4] = {1, 0, -1, 0};
int x_dir[4] = {0, 1, 0, 0};

void rotation(int num, int d){
    int temp;
    //시계방향
    if(!d){
        temp = circle[num][M];
        for(int i = M - 1; i > 0; i--) circle[num][i + 1] = circle[num][i];
        circle[num][1] = temp;
    }
    //반시계방향
    else{
        temp = circle[num][1];
        for(int i = 1; i < M; i++)circle[num][i] = circle[num][i + 1];
        circle[num][M] = temp;
    }
}

void k_rot(int x, int d, int k){
    int n = 1;
    int num;
    int temp;

    while(x * n <= N){
        num = x * n;
        temp = 0;
        while(k != temp++) rotation(num, d);
        n++;
    }
}

bool elimination(int r, int x, bool visited[][51]){
    if(visited[r][x] || !circle[r][x]) return false;
    
    int tr, tx;
    int nr, nx;
    int n = circle[r][x];
    bool p = false;
    queue<pair<int, int>> q;        
    q.push({r,x});

    while(!q.empty()){
        tr = q.front().first;
        tx = q.front().second;
        q.pop();
        if(p) circle[tr][tx] = 0;
        for(int i = 0; i < 4; i++){
            nr = tr + r_dir[i];
            nx = (tx + x_dir[i] - 1) % M + 1;
            if(nr > 0 && nr <= N && !visited[nr][nx] && circle[nr][nx] == n){
                q.push({nr, nx});
                p = true;
                visited[nr][nx] = true;
            }
        }
    }
    if(!p) return false;
    circle[r][x] = 0;
    return true;
}

pair<int, int> get_sum(){
    int s = 0;
    int n = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(circle[i][j]){
                s += circle[i][j];
                n++;
            }
        }
    }
    return {s, n};
}

void change_all(){
    pair<int, int> s = get_sum();
    double avg = (double)s.first / s.second;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(!circle[i][j]) continue;
            if(circle[i][j] > avg) circle[i][j]--;
            else if(circle[i][j] < avg) circle[i][j]++;
        }
    }
}

void integrate(int x, int d, int k){
    bool visited[51][51] = {0,};
    bool is_change = 0;

    k_rot(x, d, k);

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++) is_change += elimination(i, j, visited);
    }

    if(is_change) return;
    change_all();
}

int main(){
    int x, d, k;

    cin >> N >> M >> T;
    x_dir[3] = M - 1;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++) cin >> circle[i][j];
    }

    while(T--){
        cin >> x >> d >> k;
        integrate(x, d, k);
    }

    cout << get_sum().first << endl;

    return 0;
}