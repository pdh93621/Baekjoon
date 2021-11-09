#include <iostream>

using namespace std;

int dp5[501];

int num2(int i){
    if(i % 2){
        return 0;
    }
    return 1 + num2(i / 2);
}

int num5(int i){
    if(i % 5){
        return 0;
    }
    return 1 + num5(i / 5);
}

int main(){

    int N;
    cin >> N;

    dp5[0] = 0;

    for(int i = 1; i <= N; i++){
        dp5[i] = dp5[i - 1] + num5(i);
    }

    cout << dp5[N] << endl;

    return 0;
}