#include <iostream>
#include <stack>
#include <utility>

using namespace std;

int board[20][20];
int temp_board[20][20];
int original[20][20];
int N;

int x_dir[4] = {-1, 0, 0, 1};
int y_dir[4] = {0, -1, 1, 0};

int result = 0;
int directions[5];

void look_board(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void reset(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            board[i][j] = original[i][j];
        }
    }
}

void copyboard(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            temp_board[i][j] = board[i][j];
        }
    }
}

bool no_change(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(board[i][j] != temp_board[i][j]){
                return false;
            }
        }
    }
    return true;
}

void find_max(){
    int temp = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            temp = max(temp, board[i][j]);
        }
    }
    result = max(temp, result);
    //look_board();
}

void move(int dir){
    stack<pair<int, bool>> temp;
    int itemp;
    int size;
    if(x_dir[dir] == 0){
        for(int i = 0; i < N; i++){
            for(int j = 0; j <= N - 1; j++){
                itemp = (N - 1) * (y_dir[dir] + 1) / 2 + (-1) * y_dir[dir] * j;
                if(board[i][itemp]){
                    if(temp.empty() || temp.top().first != board[i][itemp] || temp.top().second){
                        temp.push(make_pair(board[i][itemp], false));
                    }
                    else{
                        temp.pop();
                        temp.push(make_pair(2 * board[i][itemp], true));
                    }
                    board[i][itemp] = 0;
                }
            }
            size = temp.size();
            while(size){
                board[i][(1 + y_dir[dir]) / 2 * N + (-1) * y_dir[dir] * size + (y_dir[dir] - 1) / 2] = temp.top().first;
                temp.pop();
                size--;
            }
        }
    }
    else{
        for(int i = 0; i < N; i++){
            for(int j = 0; j <= N - 1; j++){
                itemp = (N - 1) * (x_dir[dir] + 1) / 2 + (-1) * x_dir[dir] * j;
                if(board[itemp][i]){
                    if(temp.empty() || temp.top().first != board[itemp][i] || temp.top().second){
                        temp.push(make_pair(board[itemp][i], false));
                    }
                    else{
                        temp.pop();
                        temp.push(make_pair(2 * board[itemp][i], true));
                    }
                    board[itemp][i] = 0;
                }
            }
            size = temp.size();
            while(size){
                board[(1 + x_dir[dir]) / 2 * N + (-1) * x_dir[dir] * size + (x_dir[dir] - 1) / 2][i] = temp.top().first;
                temp.pop();
                size--;
            }
        }
    }
    //look_board();
}

void dfs(int n){
    if(n == 5){
        reset();
        for(auto dir: directions){
            copyboard();
            move(dir);
            if(no_change()) return;
        }
        find_max();
        return;
    }

    for(int i = 0; i < 4; i++){
        directions[n] = i;
        dfs(n + 1);
    }
}

int main(){

    cin >> N;
    int t;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> t;
            board[i][j] = t;
            original[i][j] = t;
        }
    }

    dfs(0);
    reset();
    find_max();

    cout << result << endl;
    
    return 0;
}