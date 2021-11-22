#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int N;
int K;
int L;
int board[101][101];
int x_dir[4] = {0, -1, 0, 1};
int y_dir[4] = {1, 0, -1, 0};
int current_dir = 0;
queue<pair<int, char>> dirs;
queue<pair<int, int>> snake;
pair<int, int> head = make_pair(1, 1);
pair<int, int> tail = make_pair(1, 1);
int time = 0;

void look_snake(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool gogo(int t, char d){
    t -= time;
    while(t--){
        time++;
        // cout << time - 1 << "\n";
        // look_snake();
        head.first += x_dir[current_dir];
        head.second += y_dir[current_dir];
        if(head.first < 1 || head.first > N || head.second < 1 || head.second > N || board[head.first][head.second] == 2) return false;
        snake.push(make_pair(head.first, head.second));
        
        if(board[head.first][head.second] == 0){
            board[tail.first][tail.second] = 0;
            tail = snake.front();
            snake.pop();
        }

        board[head.first][head.second] = 2;        
    }

    if(d == 'L') current_dir = (current_dir + 1) % 4;
    else current_dir = (current_dir + 3) % 4;    

    return true;
}

int main(){
    int temp_x;
    int temp_y;

    int temp_t;
    char temp_d;

    cin >> N >> K;

    for(int k = 0; k < K; k++){
        cin >> temp_x >> temp_y;
        board[temp_x][temp_y] = 1;
    }

    cin >> L;
    for(int l = 0; l < L; l++){
        cin >> temp_t >> temp_d;
        dirs.push(make_pair(temp_t, temp_d));
    }
    dirs.push(make_pair(1000, 'L'));

    //snake.push(head);
    board[1][1] = 2;

    while(gogo(dirs.front().first, dirs.front().second)) dirs.pop();

    cout << time << endl;
    return 0;
}