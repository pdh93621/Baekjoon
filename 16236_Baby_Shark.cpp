#include <iostream>
#include <queue>
#include <utility>
#include <list>

using namespace std;

int N;
int sea[20][20];
int shark_size = 2;
int eat = 0;

list<pair<int, int>> foods;

int x_dir[4] = {-1, 0, 0, 1};
int y_dir[4] = {0, -1, 1, 0};

int x;
int y;

int searching_food(){
    int result = 10000;
    int nx, ny;
    int visited[20][20] = {0,};
    int temp;
    pair<int, int> eat_poss = {30, 0};
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 1;
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        if(result < visited[x][y]) break;
        q.pop();
        for(int i = 0; i < 4; i++){
            nx = x + x_dir[i];
            ny = y + y_dir[i];
            if(nx >= 0 && ny >= 0 && nx < N && ny < N && !visited[nx][ny]){
                temp = sea[nx][ny];
                if(!temp || temp == shark_size){
                    q.push({nx, ny});
                    visited[nx][ny] = visited[x][y] + 1;
                }
                else if(temp < shark_size){
                    result = visited[x][y];
                    visited[nx][ny] = visited[x][y] + 1;
                    eat_poss = min(eat_poss, {nx, ny});
                }
            }
        }
    }
    
    if(eat_poss.first > 20) return 0;
    x = eat_poss.first;
    y = eat_poss.second;
    foods.remove({x, y});
    sea[x][y] = 0;

    if(++eat == shark_size){
        shark_size++;
        eat = 0;
    }

    return result;
}

void look_sea(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cout << sea[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}

int main(){
    cin >> N;
    int time = 0;
    int add_time;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> sea[i][j];
            if(sea[i][j] == 9){
                x = i;
                y = j;
                sea[i][j] = 0;
            }
            else if(sea[i][j]){
                foods.push_back({i, j});
            }
        }
    }

    while(!foods.empty()){
        add_time = searching_food();
        if(add_time) time += add_time;
        else break;
        //look_sea();
    }
    cout << time << endl;

    return 0;
}