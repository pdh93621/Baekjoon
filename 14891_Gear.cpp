#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool gears[4][8];
bool visited[4];

void look_gears(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 8; j++){
            cout << gears[i][j];
        }
        cout << "\n";
    }
}

void reset_visited(){
    for(int i = 0; i < 4; i++){
        visited[i] = false;
    }
}

void rotation(int gnum, int rot){
    int start = 7 * (1 + rot) / 2;
    bool temp = gears[gnum][start];
    for(int i = 0; i < 7; i++) gears[gnum][start - rot * i] = gears[gnum][start - rot * (i + 1)];
    gears[gnum][7 - start] = temp;
}

void total_rot(int gnum, int rot){
    visited[gnum] = true;
    if(gnum < 3 && !visited[gnum + 1] && gears[gnum][2] != gears[gnum + 1][6]) total_rot(gnum + 1, rot * (-1));
    if(gnum > 0 && !visited[gnum - 1] && gears[gnum][6] != gears[gnum - 1][2] ) total_rot(gnum - 1, rot * (-1));
    rotation(gnum, rot);
}

int main(){
    int K;
    int gnum;
    int rot;
    int result = 0;
    string temp;
    for(int i = 0; i < 4; i++){
        cin >> temp;
        for(int j = 0; j < 8; j++){
            gears[i][j] = temp[j] - '0';
        }
    }
    cin >> K;
    for(int i = 0; i < K; i++){
        cin >> gnum >> rot;
        total_rot(gnum - 1, rot);
        reset_visited();
    }

    for(int i = 0; i < 4; i++){
        result += gears[i][0] * pow(2, i);
    }

    cout << result << endl;
    return 0;
}