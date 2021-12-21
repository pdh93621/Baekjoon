#include <iostream>
#include <queue>
#include <utility>

using namespace std;

typedef struct{
    bool is_cloud = false;
    int water = 0;
} info;

int N, M;

info A[50][50];
queue<pair<int, int>> clouds;
queue<pair<int, int>> m_clouds;
int x_dir[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int y_dir[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

void look_A(bool k){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(k) cout << A[i][j].is_cloud << "\t";
            else cout << A[i][j].water << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}

void look_clouds(){
    int s = clouds.size();
    while(s--){
        cout << clouds.front().first << clouds.front().second << " ";
        clouds.push(clouds.front());
        clouds.pop();
    }
    cout << "\n";
}

void look_mclouds(){
    int s = m_clouds.size();
    while(s--){
        cout << m_clouds.front().first << m_clouds.front().second << " ";
        m_clouds.push(m_clouds.front());
        m_clouds.pop();
    }
    cout << "\n";
}

int modN(int n){
    if(n >= N) return n - N;
    if(n < 0) return N + n;
    return n;
}

void move_cloud(int d, int s){
    int x, y;
    x = clouds.front().first;
    y = clouds.front().second;
    clouds.pop();
    s = s % N;
    x = modN(x + s * x_dir[d]);
    y = modN(y + s * y_dir[d]);

    A[x][y].water++;
    A[x][y].is_cloud = true;
    m_clouds.push({x, y});
}

void copy_berg(){
    int x, y;
    int nx, ny;
    x = m_clouds.front().first;
    y = m_clouds.front().second;
    m_clouds.pop();

    for(int i = 0; i < 4; i++){
        nx = x + x_dir[2 * i + 1];
        ny = y + y_dir[2 * i + 1];
        if(nx >= 0 && ny >= 0 && nx < N && ny < N && A[nx][ny].water) A[x][y].water++;
    }
}

void make_cloud(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(A[i][j].is_cloud) A[i][j].is_cloud = false;
            else if(A[i][j].water >= 2) {
                clouds.push({i, j});
                A[i][j].water -= 2;
            }
        }
    }
}

int get_sum(){
    int result = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) result += A[i][j].water;
    }
    return result;
}

void integrate(int d, int s){
    while(!clouds.empty()) move_cloud(d, s);
    //look_A(1);
    //look_mclouds();
    while(!m_clouds.empty()) copy_berg();
    //look_A(0);
    make_cloud();
    //look_clouds();
    //look_A(0);
}

int main(){
    int d, s;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cin >> A[i][j].water; 
    }

    clouds.push({N - 1, 0});
    clouds.push({N - 2, 0});
    clouds.push({N - 1, 1});
    clouds.push({N - 2, 1});

    while(M--){
        cin >> d >> s;
        integrate(d - 1, s);
    }

    cout << get_sum() << endl;

    return 0;
}