#include <iostream>

using namespace std;

typedef struct{
    int bn;
    int loc;
} location;

int dice_num[10];
int order[10];

int unit[4];

bool board[4][27];
int score[4][15];
int result = 0;
location k[4];

bool move(int i){
    int b = k[order[i]].bn;
    int l = k[order[i]].loc;

    board[b][l] = false;

    if(b){
        if(!score[b][l]) return false;
    }
    else{
        if(l >= 21) return false;
        else if(l < 20 && !(l % 5)){
            k[order[i]].bn = l / 5;
            k[order[i]].loc = 0;
        }
    }

    k[order[i]].loc += dice_num[i];
    b = k[order[i]].bn;
    l = k[order[i]].loc;
    board[b][l] = true;
}

void comb(int n, int k){
    if(n == 10){
        int temp = 0;
        for(int i = 0; i < 10; i++){
            if(move(i)){
                int b = k[order[i]].bn;
                int l = k[order[i]].loc;
            }
        }
    }

    for(int i = 0; i <= k; i++){
        order[n] = i;
        comb(n + 1, max(k, i) + 1);
    }
}

int main(){
    for(int i = 0; i < 10; i++) cin >> dice_num[i]; 

    score[1] = {10, 13, 16, 19, 25, 30, 35, 40};
    score[2] = {20, 22, 24, 25, 30, 35, 40};
    score[3] = {30, 28, 27, 26, 25, 30, 35, 40};

    return 0;
}