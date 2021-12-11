#include <iostream>
#include <utility>

using namespace std;
typedef struct{
    int x, y, d;
    bool live;
}info;

info fish[17];
info shark;
int space[4][4];

int x_dir[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int y_dir[8] = {0, -1, -1, -1, 0, 1, 1, 1};

void reset_space(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++) space[i][j] = 0;
    }
}

void look_space(){
    cout << "\n";
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++) cout << space[i][j] << " ";
        cout << "\n";
    }

}

int find_dir(info f){
    int nx, ny;
    int x = f.x;
    int y = f.y;
    int d = f.d;
    for(int i = 0; i < 8; i++){
        nx = x + x_dir[(d + i) % 8];
        ny = y + y_dir[(d + i) % 8];
        if(nx >=0 && ny >= 0 && nx < 4 && ny < 4 && space[nx][ny] != -1) return (d + i) % 8;
    }
    return -1;
}

void move_fish(int num){
    int d = find_dir(fish[num]);
    if(d < 0) return;
    int x = fish[num].x;
    int y = fish[num].y;
    fish[num].d = d;
    int nx = x + x_dir[d];
    int ny = y + y_dir[d];

    if(space[nx][ny]) {
        int num2 = space[nx][ny];
        fish[num2].x = x;
        fish[num2].y = y;
        space[x][y] = num2; 
    }
    else space[x][y] = 0;

    fish[num].x = nx;
    fish[num].y = ny;
    space[nx][ny] = num;
}

int move_shark(int m){
    int num;
    int nx = shark.x + m * x_dir[shark.d];
    int ny = shark.y + m * y_dir[shark.d];
    if(nx >= 0 && ny >= 0 && nx < 4 && ny < 4 && space[nx][ny]){
        space[shark.x][shark.y] = 0;
        num = space[nx][ny];
        shark = fish[num];
        fish[num].live = false;
        space[nx][ny] = -1;
        return num;
    }
    else return -1;
}

int integrate(){
    //기존 데이터 저장
    info temp_shark = shark;
    info temp_fish[17];
    for(int i = 1; i <= 16; i++) temp_fish[i] = fish[i];

    int temp;
    int result = 0;
    for(int i = 1; i <= 16; i++) if(fish[i].live) move_fish(i);

    for(int i = 1; i <= 3; i++){
        temp = move_shark(i);
        if(temp < 0) continue;
        result = max(temp + integrate(), result);
        
        //초기화
        reset_space();
        for(int i = 1; i <= 16; i++){
            fish[i] = temp_fish[i];
            shark = temp_shark;
            if(fish[i].live) space[fish[i].x][fish[i].y] = i;
            space[shark.x][shark.y] = -1;
        }
    }

    return result;
}

int main(){
    int dir;
    int num;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cin >> num >> dir;
            fish[num] = {i, j, dir - 1, true};
            space[i][j] = num;
        }
    }

    num = space[0][0];
    shark = fish[num];
    fish[num].live = false;
    space[0][0] = -1;

    cout << num + integrate() << endl;
    return 0;
}