#include <iostream>

using namespace std;

void inflate(char (*stars)[90] , int num){
    int temp = num / 3;
    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){
            if ((i >= num / 3 and i < 2 * num / 3) and (j >= num / 3 and j < 2 * num / 3)){
                stars[i][j] = ' '; 
            }
            else {
                stars[i][j] = stars[i % temp][j % temp];
            }
        }
    }
}

int main(){
    int N;
    cin >> N;
    char stars[90][90];
    char star = '*';
    stars[0][0] = star;

    int num = 3;
    while (num <= N){
        inflate(stars, num);
        num *= 3;
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << stars[i][j];
        }
        cout << endl;
    }
    return 0;
}