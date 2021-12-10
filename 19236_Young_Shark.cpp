#include <iostream>
#include <utility>

using namespace std;
typedef struct{
    int x, y, d;
}info;

info ori_info[17];
info fish[17];
info shark;

int ori_space[4][4];
int space[4][4];

int x_dir[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int y_dir[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int behave[15];

int result;

void look_behave(){
    for(int i = 0; i < 15; i++) cout << behave[i] << " ";
    cout << "\n";
}

void look_space(){
    cout << "\n";
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++) cout << space[i][j] << " ";
        cout << "\n";
    }
}

void reset_info(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++) space[i][j] = ori_space[i][j];
    }
    for(int i = 1; i < 17; i++) fish[i] = ori_info[i];
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
        fish[num].x = -1;
        space[nx][ny] = -1;
        return num;
    }
    else return -1;
}

void integrate(int b){
    if(b == 15){
        int eat = space[0][0];
        int eaten;
        int m = 0;
        shark = fish[eat];
        fish[eat].x = -1;
        space[0][0] = -1;

        while(m < 15) {
            for(int i = 1; i <= 16; i++) if(fish[i].x >= 0) move_fish(i);            
            eaten = move_shark(behave[m]);
            if(eaten < 0) break;
            eat += eaten;
            m++;
        }
        
        look_behave();
        result = max(eat, result);
        reset_info();
    }
    else {
        for(int i = 1; i <= 3; i++){
            behave[b] = i;
            integrate(b + 1);
        }
    }
}

int main(){
    int dir;
    int num;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cin >> num >> dir;
            fish[num] = {i, j, dir - 1};
            ori_info[num] = fish[num];
            space[i][j] = num;
            ori_space[i][j] = num;
        }
    }
    
    integrate(0);
    cout << result << endl;
    
    return 0;
}