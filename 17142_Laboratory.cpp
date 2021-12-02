#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int lab[50][50];
int original[50][50];
vector<pair<int, int>> virus;
int activated[11];
int num_empty = 0;

int x_dir[4] = {-1, 0 , 1, 0};
int y_dir[4] = {0, 1, 0, -1};
int result = 100001;
int v_size;

void reset_lab(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) lab[i][j] = original[i][j];
    }
}

void bfs(){
    int x, y, nx, ny;
    int max_num = 2;
    int num_zero = 0;
    queue<pair<int, int>> v;
    for(int i = 1; i <= M; i++) v.push(virus[activated[i]]);

    reset_lab();
    while(!v.empty()){
        x = v.front().first;
        y = v.front().second;
        v.pop();
        for(int i = 0; i < 4; i++){
            nx = x + x_dir[i];
            ny = y + y_dir[i];
            if(nx >= 0 && ny >= 0 && nx < N && ny < N){
                if(lab[nx][ny] == 0 || lab[nx][ny] == 2){
                    v.push({nx, ny});
                    if(!lab[nx][ny]){
                        num_zero++;
                        max_num = max(max_num, lab[x][y] + 1);
                    }
                    lab[nx][ny] = lab[x][y] + 1;
                }
            }
        }
    }

    if(num_zero == num_empty) result = min(max_num - 2, result);    
    return;
}

void solution(int n){
    if(n > M) bfs();
    else{
        for(int i = 0; i < v_size; i++){
            if(i > activated[n - 1]){
                activated[n] = i;
                solution(n + 1);
            }
        }
    }
}

int main(){
    cin >> N >> M;
    int k;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> lab[i][j];
            if(lab[i][j] == 2) virus.push_back({i, j});
            else if(!lab[i][j]) num_empty++;
            original[i][j] = lab[i][j];
        }
    }

    v_size = virus.size();
    activated[0] = -1;
    solution(1);

    if(result == 100001) result = -1;
    
    cout << result << endl;

    return 0;
}