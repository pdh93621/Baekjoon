#include <iostream>
#include <queue>
#define Green 0
#define Blue 1

using namespace std;

bool GB[2][6][4];
int score;

int num_pile(int j, int color){
    int num = 0;
    while(num < 6 && !GB[color][num][j]) num++;
    return --num;
}

int num_block(){
    int nb = 0;
    for(int i = 0; i < 2; i++){
        for(int j = 2; j < 6; j++){
            for(int k = 0; k < 4; k++) nb += GB[i][j][k];
        }
    }
    return nb;
}

void look_GB(){
    cout << "Green" << endl;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 4; j++) cout << GB[Green][i][j] << " ";
        cout << endl;
    }
    cout << "Blue" << endl;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 6; j++) cout << GB[Blue][j][i] << " ";
        cout << endl;
    }
}

void R2GB(int t, int x, int y, bool color){
    int b[2];
    int c = !color * y + color * x;
    t -= 2;
    int h1 = num_pile(c, color);
    int h2;
    
    if(t < 0) {
        GB[color][h1][c] = 1;
        return;
    }
    b[0] = c;
    b[1] = c + (t == color);
    if(b[0] == b[1]) {
        GB[color][h1][c] = 1;
        GB[color][h1 - 1][c] = 1;
    }
    else{
        h2 = min(h1, num_pile(c + 1, color));
        GB[color][h2][c] = 1;
        GB[color][h2][c + 1] = 1;
    }
}

void get_score(bool color){
    int a;
    queue<int> q;
    int temp;
    //가득찬 행 제거
    for(int i = 2; i < 6; i++){
        a = 0;
        for(int j = 0; j < 4; j++) a += GB[color][i][j];
        if(a == 4){
            for(int j = 0; j < 4; j++) GB[color][i][j] = 0;
            score++;
            q.push(i);
        }
    }

    while(!q.empty()){
        temp = q.front();
        q.pop();
        for(int i = temp - 1; i >= 0; i--){
            for(int j = 0; j < 4; j++){
                GB[color][i + 1][j] = GB[color][i][j];
                GB[color][i][j] = 0;
            }
        }
    }
}

void cut_down(bool color){
    int a1 = 0;
    for(int j = 0; j < 4; j++){
        if(GB[color][1][j]){
            a1++;
            for(int k = 0; k < 4; k++){
                if(GB[color][0][j]){
                    a1++;
                    break;
                }
            }
            break;
        }
    }

    if(!a1) return;

    for(int i = 5 - a1; i >= 2 - a1; i--){
        for(int j = 0; j < 4; j++){
            GB[color][i + a1][j] = GB[color][i][j];
            GB[color][i][j] = 0;
        }
    }
}

int main(){
    int N;
    int t, x, y;
    int k;

    cin >> N;
    
    while(N--){
        cin >> t >> x >> y;
        R2GB(t, x, y, Green);
        R2GB(t, x, y, Blue);
        get_score(Green);
        get_score(Blue);
        cut_down(Green);
        cut_down(Blue);
        //look_GB();
    }

    k = num_block();
    cout << score << '\n' << k << '\n';
    return 0;
}