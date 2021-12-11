#include <iostream>

using namespace std;

typedef struct{
    int root;
    int location;
    bool goal;
}info;

int dice_num[10];
bool roots[4][21];
int scores[4][21];
info units[4];

int result;

bool out_range(int root, int location){
    if(!root) if(location > 20) return true;
    else{
        if(root == 1 || root == 3) if(location > 8) return true;
        else {
            if(location > 7) return true;
        }
    }

    return false;
}

int move(int u, int dn){
    if(unit[u].goal) return -1;
    int root = units[u].root;
    int location = units[u].location;
    int num = dice_num[dn];
    
    roots[root][location] = false;

    if(!(location % 10) && location / 10 < 4){
        units[u].root = location / 10;
        units[u].location = 0;
    }

    units[u].location += num;

    if(out_range(units[u].root, units[u].location)) {
        units[u].goal = true;
        return 0;
    }

    roots[units[u].root][units[u].location] = true;
    return scores[units[u].root][units[u].location];    
}

void dfs(int u, int k, int n){
    if(n > 10) result = max(result, k);
    else{
        for(int i = 0; i <= u; i++){
            dfs(i + 1, k + move(i, n));
        }
    }
}

int main(){
    for(int i = 0; i < 10; i++) cin >> dice_num[i];
    for(int i = 0; i <= 20; i++) scores[0][i] = 2 * i;
    scores[1] = {10, 13, 16, 19, 25, 30, 35, 40};
    scores[2] = {20, 22, 24, 25, 30, 35, 40};
    scores[3] = {30, 28, 27, 26, 25, 30, 35, 40};

    return 0;
}