#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

char cube[6][3][3];
char colors[6] = {'o', 'r', 'g', 'b', 'y', 'w'};

void look_U(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++) cout << cube[5][i][j];
        cout << "\n";
    }
}

void reset_cube(){
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++) cube[i][j][k] = colors[i];
        }
    }
}

pair<int, int> f2n(char face){
    switch (face)
    {
    case 'B':
        return make_pair(0, -1);
    case 'F':
        return make_pair(0, 1);
    case 'L':
        return make_pair(1, -1);
    case 'R':
        return make_pair(1, 1);
    case 'D':
        return make_pair(2, -1);
    case 'U':
        return make_pair(2, 1);
    }
}

int p2i(int xyz, int loc){
    if(loc < 0) loc = 0;
    return 2 * ((xyz + 3) % 3) + loc;
}

void rotate(pair<int, int> face, int rot){
    int cw = (-1) * face.second * rot;
    int f = face.first;
    int s = face.second;
    int f_num = p2i(f,s);
    // rotate face
    char t1 = cube[f_num][0][0];
    char t2 = cube[f_num][1][0];
    if(cw){        
        cube[f_num][0][0] = cube[f_num][0][2];
        cube[f_num][0][2] = cube[f_num][2][2];
        cube[f_num][2][2] = cube[f_num][2][0];
        cube[f_num][2][0] = t1;
        cube[f_num][1][0] = cube[f_num][0][1];
        cube[f_num][0][1] = cube[f_num][1][2];
        cube[f_num][1][2] = cube[f_num][2][1];
        cube[f_num][2][1] = t2;
    }
    else{
        cube[f_num][0][0] = cube[f_num][2][0];
        cube[f_num][2][0] = cube[f_num][2][2];
        cube[f_num][2][2] = cube[f_num][0][2];
        cube[f_num][0][2] = t1;
        cube[f_num][1][0] = cube[f_num][2][1];
        cube[f_num][2][1] = cube[f_num][1][2];
        cube[f_num][1][2] = cube[f_num][0][1];
        cube[f_num][0][1] = t2;
    }

    // rotate rounds
    
    int fix_num = s + 1;
    char temp[3];
    bool ox;
    int round[4] = {p2i(f + cw, s), p2i(f + 2 * cw, s), p2i(f + cw, - s), p2i(f + 2 * cw, - s)};
    for(int i = 0; i < 3; i++){
        if(cw > 0) temp[i] = cube[round[3]][fix_num][i];
        else temp[i] = cube[round[3]][i][fix_num];
    }
    for(int i = 2; i >= 0; i--){
        ox = (round[i] + round[i + 1]) % 2;
        for(int j = 0; j < 3; j++){
            if(pow(-1, i) * cw > 0) cube[round[i + 1]][fix_num][j] = cube[round[i]][!ox * 2 + (2 * ox - 1) * j][fix_num];
            else cube[round[i + 1]][j][fix_num] = cube[round[i]][fix_num][!ox * 2 + (2 * ox - 1) * j];
        }
    }
    ox = (round[3] + round[0]) % 2;
    for(int i = 0; i < 3; i++){
        if(cw > 0) cube[round[0]][i][fix_num] = temp[!ox * 2 + (2 * ox - 1) * i];
        else cube[round[0]][fix_num][i] = temp[!ox * 2 + (2 * ox - 1) * i];
    }    
}

int rton(char rot){
    if (rot == '+') return 1;
    else return -1;
}

int main(){
    int T;
    int n;
    string temp;
    cin >> T;
    
    while(T--){
        reset_cube();
        cin >> n;
        while(n--){
            cin >> temp;
            rotate(f2n(temp[0]), rton(temp[1]));
            
        }   
        look_U();        
    }

    return 0;
}