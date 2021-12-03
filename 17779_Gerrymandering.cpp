#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int N;
int city[20][20];
int result = 10000000;

int is_in5(int x, int y, int r, int c, int d1, int d2){
    if(c + r >= x + y && c + r <= x + y + 2 * d2 && c - r <= y - x && c - r >= y - x - 2 * d1) return 4;
    else{
        if(0 <= r && r < x + d1 && 0 <= c && c <= y) return 0;
        else if(0 <= r && r <= x + d2 && y < c && c < N) return 1;
        else if(x + d1 <= r && r < N && 0 <= c && c < y - d1 + d2) return 2;
        else return 3;
    }
}

int maxmin(int x, int y, int d1, int d2){
    int m = 10000000;
    int M = 0;
    int population[5] = {0,};
    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++) population[is_in5(x, y, r, c, d1, d2)] += city[r][c];
    }
    for(int i = 0; i < 5; i++){
        M = max(M, population[i]);
        m = min(m, population[i]);
    }
    return M - m;
}

void divide_city(int x, int y){
    int m = 10000000;
    int M = 0;
    int population[5] = {0,};
    for(int d1 = 1; d1 <= y; d1++){
        for(int d2 = 1; y + d2 < N && x + d1 + d2 < N; d2++){
            result = min(result, maxmin(x, y, d1, d2));
        }
    }
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cin >> city[i][j];
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) divide_city(i, j);
    }

    cout << result << endl;
    return 0;
}