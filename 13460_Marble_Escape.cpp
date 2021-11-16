#include <iostream>
#include <string>

using namespace std;

int N, M;
char board[10][10];

int red_x, red_y, blue_x, blue_y;
int goal_x, goal_y;

int result = 11;

int dir_x[4] = {-1, 0, 0, 1};
int dir_y[4] = {0, -1, 1, 0};

void look_board(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void move_red(int dir){
    int n = 1;
    while(board[red_x + n * dir_x[dir]][red_y + n * dir_y[dir]] == '.'){
        n++;
    }
    n--;
    board[red_x][red_y] = '.';    
    red_x += n * dir_x[dir];
    red_y += n * dir_y[dir];
    board[red_x][red_y] = 'R';
}

void move_blue(int dir){
    int n = 1;
    while(board[blue_x + n * dir_x[dir]][blue_y + n * dir_y[dir]] == '.'){
        n++;
    }
    n--;
    board[blue_x][blue_y] = '.';
    blue_x += n * dir_x[dir];
    blue_y += n * dir_y[dir];
    board[blue_x][blue_y] = 'B';
}

void move_board(int dir){
    move_red(dir);
    move_blue(dir);
    move_red(dir);
    //look_board();
}

void dfs(int n, int dir){
    if(n >= result){
        return;
    }

    int temp_rx = red_x;
    int temp_ry = red_y;
    int temp_bx = blue_x;
    int temp_by = blue_y;

    move_board(dir);
    
    if(temp_rx != red_x || temp_ry != red_y || temp_bx != blue_x || temp_by != blue_y){
        if(min(temp_bx, blue_x) > goal_x || max(temp_bx, blue_x) < goal_x || min(temp_by, blue_y) > goal_y || max(temp_by, blue_y) < goal_y){
            if(min(temp_rx, red_x) <= goal_x && max(temp_rx, red_x) >= goal_x && min(temp_ry, red_y) <= goal_y && max(temp_ry, red_y) >= goal_y){
                board[red_x][red_y] = '.';
                move_blue(dir);
                if(min(temp_bx, blue_x) > goal_x || max(temp_bx, blue_x) < goal_x || min(temp_by, blue_y) > goal_y || max(temp_by, blue_y) < goal_y){
                    result = n;
                }                
            }
            else{
                for(int i = 1; i <= 3; i++){
                    dfs(n + 1, (dir + i) % 4);
                }
            }
        }

        board[red_x][red_y] = '.';
        board[temp_rx][temp_ry] = 'R';
        board[blue_x][blue_y] = '.';
        board[temp_bx][temp_by] = 'B';
        red_x = temp_rx;
        red_y = temp_ry;
        blue_x = temp_bx;
        blue_y = temp_by;
    }
}

int main(){
    cin >> N >> M;

    int org_rx;
    int org_ry;
    int org_bx;
    int org_by;

    for(int i = 0; i < N; i++){
        string temp;
        cin >> temp;
        for(int j = 0; j < M; j++){
            board[i][j] = temp[j];
            if(temp[j] == 'R'){
                red_x = i;
                red_y = j;
                org_rx = i;
                org_ry = j;
            }
            else if(temp[j] == 'B'){
                blue_x = i;
                blue_y = j;
                org_bx = i;
                org_by = j;
            }
            else if(temp[j] == 'O'){
                goal_x = i;
                goal_y = j;
                board[i][j] = '.';
            }
        }
    }

    for(int i = 0; i < 4; i++){
        dfs(1, i);
    }

    //look_board();
    if(result > 10) result = -1;

    cout << result << endl;
    
    return 0;
}