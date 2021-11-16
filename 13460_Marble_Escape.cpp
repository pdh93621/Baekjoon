#include <iostream>
#include <string>

using namespace std;

int N, M;
char board[10][10];

int red_x, red_y, blue_x, blue_y;
int goal_x, goal_y;

int result = 1001;

void move_left(){
    int n = 0;
    int m = 0;
    if(red_y <= blue_y){
        while(board[red_x][red_y - n - 1] == '.'){
            n++;
        }
        board[red_x][red_y] = '.';
        board[red_x][red_y - n] = 'R';

        while(board[blue_x][blue_y - m - 1] == '.'){
            m++;
        }
        board[blue_x][blue_y] = '.';
        board[blue_x][blue_y - m] = 'B';
    }
    else{
        while(board[blue_x][blue_y - m - 1] == '.'){
            m++;
        }
        board[blue_x][blue_y] = '.';
        board[blue_x][blue_y - m] = 'B';

        while(board[red_x][red_y - n - 1] == '.'){
            n++;
        }
        board[red_x][red_y] = '.';
        board[red_x][red_y - n] = 'R';
    }
    red_y -= n;
    blue_y -= m;
}

void move_right(){
    int n = 0;
    int m = 0;
    if(red_y >= blue_y){
        while(board[red_x][red_y + n + 1] == '.'){
            n++;
        }
        board[red_x][red_y] = '.';
        board[red_x][red_y + n] = 'R';

        while(board[blue_x][blue_y + m + 1] == '.'){
            m++;
        }
        board[blue_x][blue_y] = '.';
        board[blue_x][blue_y + n] = 'B';
    }
    else{
        while(board[blue_x][blue_y + m + 1] == '.'){
            m++;
        }
        board[blue_x][blue_y] = '.';
        board[blue_x][blue_y + m] = 'B';

        while(board[red_x][red_y + n + 1] == '.'){
            n++;
        }
        board[red_x][red_y] = '.';
        board[red_x][red_y + n] = 'R';
    }
    red_y += n;
    blue_y += m;
}

void move_up(){
    int n = 0;
    int m = 0;
    if(red_x <= blue_x){
        while(board[red_x - n - 1][red_y] == '.'){
            n++;
        }
        board[red_x][red_y] = '.';
        board[red_x - n][red_y] = 'R';

        while(board[blue_x - m - 1][blue_y] == '.'){
            m++;
        }
        board[blue_x][blue_y] = '.';
        board[blue_x - m][blue_y] = 'B';
    }
    else{
        while(board[blue_x - m - 1][blue_y] == '.'){
            m++;
        }
        board[blue_x][blue_y] = '.';
        board[blue_x - m][blue_y] = 'B';
        
        while(board[red_x - n - 1][red_y] == '.'){
            n++;
        }
        board[red_x][red_y] = '.';
        board[red_x - n][red_y] = 'R';
    }
    red_x -= n;
    blue_x -= m;
}

void move_down(){
    int n = 0;
    int m = 0;
    if(red_x >= blue_x){
        while(board[red_x + n + 1][red_y] == '.'){
            n++;
        }
        board[red_x][red_y] = '.';
        board[red_x + n][red_y] = 'R';

        while(board[blue_x + m + 1][blue_y] == '.'){
            m++;
        }
        board[blue_x][blue_y] = '.';
        board[blue_x + m][blue_y] = 'B';
    }
    else{
        while(board[blue_x + m + 1][blue_y] == '.'){
            m++;
        }
        board[blue_x][blue_y] = '.';
        board[blue_x + m][blue_y] = 'B';
        
        while(board[red_x + n + 1][red_y] == '.'){
            n++;
        }
        board[red_x][red_y] = '.';
        board[red_x + n][red_y] = 'R';
    }
    red_x += n;
    blue_x += m;

}

void shake(int dir){
    if(dir == 0){
        move_left();
    }
    else if(dir == 1){
        move_up();
    }
    else if(dir == 2){
        move_down();
    }
    else if(dir == 3){
        move_right();
    }
}



int main(){
    char dirs[4] = {'L', 'U', 'D', 'R'};
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
                temp[j] = '.';
            }
        }
    }



    if(result > 10) result = -1;

    cout << result << endl;
    
    return 0;
}