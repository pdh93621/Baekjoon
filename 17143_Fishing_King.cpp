#include <iostream>

using namespace std;

typedef struct{
    int r, c, s, d ,z;
    bool dead = false;
}info;

typedef struct{
    int r, c, d;
}pivot;

int R, C, M;
int r_dir[4] = {0, -1, 1, 0};
int c_dir[4] = {-1, 0, 0, 1};
int result;

info sharks[10001];

void look_acua(int acua[][100], int catched){
    cout << catched << "\n";
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++) cout << acua[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}

pivot get_pivot(int r, int c, int s, int d){
    int temp = r_dir[d] + c_dir[d];
    
    
    return {r, c, d};
}

void action(int column){
    int acua[100][100] = {0,};
    for(int i = 1; i <= M; i++){
        if(sharks[i].dead) continue;
        pivot temp = get_pivot(sharks[i].r, sharks[i].c, sharks[i].s, sharks[i].d);
        if(acua[temp.r][temp.c]){
            if(sharks[i].z < sharks[acua[temp.r][temp.c]].z) {
                sharks[i].dead = true;
                continue;
            }
            else sharks[acua[temp.r][temp.c]].dead = true;
        }
        sharks[i].r = temp.r;
        sharks[i].c = temp.c;
        sharks[i].d = temp.d;
        acua[temp.r][temp.c] = i;
    }

    //catch_shark
    int k = 0;
    while(!acua[k][column] && k < R - 1) k++;
    sharks[acua[k][column]].dead = true;
    result += sharks[acua[k][column]].z;
    //look_acua(acua, sharks[acua[k][column]].z);
}

int main(){
    int r, c, s, d, z;
    cin >> R >> C >> M;
    int first_tg = 0;
    int temp = R - 1;
    for(int i = 1; i <= M; i++){
        cin >> r >> c >> s >> d >> z;
        sharks[i] = {r - 1, c - 1, s, d % 4, z, 0};
        if(!sharks[i].c) {
            if(temp >= sharks[i].r){
                temp = sharks[i].r;
                first_tg = i;
            }
        }
    }

    result += sharks[first_tg].z;
    sharks[first_tg].dead = true;

    for(int i = 1; i < C; i++) action(i);

    cout << result << endl;

    return 0;
}