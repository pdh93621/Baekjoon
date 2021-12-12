#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef struct{
    int root, num;
    bool goal = false;
}info;

int dice_num[10];

int r[4][21] = {{0,}, 
               {10, 13, 16, 19, 25, 30, 35, 40,},
               {20, 22, 24, 25, 30, 35, 40,},
               {30, 28, 27, 26, 25, 30, 35, 40,}};
bool v[4][21];
int roots_size[4] = {20, 7, 6, 7};
int result = 0;

info unit[4];

void look_v(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j <= roots_size[i]; j++) cout << v[i][j] << " ";
        cout << "\n";
    }
}

bool visited(int r, int n){
    if(v[r][n]) return true;

    if(n == roots_size[r]){
        for(int i = 0; i < 4; i++) if(v[i][roots_size[i]]) return true;
    }

    if(r > 0){
        if(n <= roots_size[r] && n >= roots_size[r] - 3){
            int diff = roots_size[r] - n;
            for(int i = 1; i < 4; i++) if(v[i][roots_size[i] - diff]) return true;
        }
    }

    return false;
}

int move(int n, int d){
    if(unit[n].goal) return -1;
    int root = unit[n].root;
    int num = unit[n].num;
    int dice = dice_num[d];
    v[root][num] = false;
    if(!root && num && !(num % 5) && num / 5 < 4){
        root = num / 5;
        num = 0;
    }
    num += dice;

    if(visited(root, num)) return -1;

    unit[n].root = root;
    unit[n].num = num;

    if(num > roots_size[root]){
        unit[n].goal = true;
        return 0;
    }
    v[root][num] = true;

    return r[unit[n].root][num];
}

void reset(info pre, int u){
    if(!unit[u].goal) v[unit[u].root][unit[u].num] = false;    
    v[pre.root][pre.num] = true;
    unit[u] = pre;
}

void dfs(int k, int score, int u_num){
    if(k == 10){
        result = max(result, score);
        return;
    }
    int temp;
    info pre_info;
    if(u_num > 3) u_num = 3;
    for(int u = 0; u <= u_num; u++){
        
        pre_info = unit[u];
        
        temp = move(u, dice_num[k]);
        if(temp < 0) continue;
        dfs(k + 1, score + temp, u_num + 1);
        reset(pre_info, u);
    }
}

int main(){
    for(int i = 0; i < 10; i++) cin >> dice_num[i];
    for(int i = 0; i < 21; i++) r[0][i] = 2 * i;

    dfs(0, 0, 0);
    cout << result << endl;

    return 0;
}