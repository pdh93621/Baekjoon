#include <iostream>

using namespace std;

int abc[21][21][21];

int w(int a, int b, int c){

    if(a <= 20 && b <= 20 && c <= 20 && a > 0 && b > 0 && c> 0){
        if(abc[a][b][c] != 0){
            return abc[a][b][c];
        }
    }

    if(a <= 0 || b <= 0 || c <= 0){
        return 1;
    }
    else if(a > 20 || b > 20 || c > 20){
        return w(20, 20, 20);
    }
    else if(a < b && b < c){
        abc[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c); 
        return abc[a][b][c];
    }
    else{
        abc[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
        return abc[a][b][c];
    }
}

int main(){

    int a,b,c;
    while(1){
        cin >> a >> b >> c;

        if (a == -1 && b == -1 && c == -1){
            break;
        }
        
        printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
    }

    return 0;
}