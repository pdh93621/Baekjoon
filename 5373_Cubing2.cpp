#include <iostream>
#include <deque>
#include <utility>
#include <string>

using namespace std;

typedef struct {
    int face, r, c;
}triple;

char colors[6] = {'r', 'o', 'b', 'g', 'w', 'y'};
char faces[6] = {'F', 'B', 'R', 'L', 'U', 'D'};
char cube[6][3][3];

int stof(char s) {
    for(int i = 0; i < 6; i++) if(s == faces[i]) return i;
}

void reset_cube() {
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) cube[i][j][k] = colors[i];
        }
    }
}

void look_Up() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) cout << cube[4][i][j];
        cout << "\n";
    }
}

void rotate_face(int face, bool cw) {
    deque<char> temp;
    char t;
    int orient = face % 2;

    for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) temp.push_back(cube[face][i][j]);
    
    for(int i = 0; i < 3; i++) {
        for(int j = 2; j >= 0; j--) {
            if(orient == cw) {
                t = temp.front();
                temp.pop_front();
            }
            else {
                t = temp.back();
                temp.pop_back();
            }
            cube[face][j][i] = t;
        }
    }
}

void rotate_round(int face, bool cw) {
    int xyz = face / 2;
    bool orient = face % 2;
    int fixed = 2 * (!orient); 
    int around[4] = {(xyz + 1) % 3 * 2, (xyz + 2) % 3 * 2, (xyz + 1) % 3 * 2 + 1, (xyz + 2) % 3 * 2 + 1};
    deque<triple> edge;
    deque<char> color;

    for(int i = 0; i < 3; i++) edge.push_back({around[0], i, fixed});
    for(int j = 2; j >= 0; j--) edge.push_back({around[1], fixed, j});
    for(int k = 2; k >= 0; k--) edge.push_back({around[2], k, fixed});
    for(int l = 0; l < 3; l++) edge.push_back({around[3], fixed, l});

    deque<triple>::iterator d;
    for(d = edge.begin(); d != edge.end(); d++) color.push_back(cube[(*d).face][(*d).r][(*d).c]);

    for(int i = 0; i < 3; i++) {
        if(orient == cw) {
            color.push_front(color.back());
            color.pop_back();
        }
        else {
            color.push_back(color.front());
            color.pop_front();
        }
    }
    for(int k = 0; k < color.size(); k++) cube[edge[k].face][edge[k].r][edge[k].c] = color[k];
}

int main(){
    int T;
    int n;
    string s;

    cin >> T;
    while(T--) {
        cin >> n;
        reset_cube();
        while(n--) {
            cin >> s;
            rotate_face(stof(s[0]), s[1] == '+');
            rotate_round(stof(s[0]), s[1] == '+');
        }
        look_Up();
    }

    return 0;
}