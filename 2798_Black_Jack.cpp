#include <iostream>

using namespace std;

int N, M;
int cards[100];
int result;

void blackjack(int n, int s, int l){
    if(n == 3){
        if(s > M) return;
        result = max(result, s);
        return;
    }
    
    for(int i = l; i < N; i++) blackjack(n + 1, s + cards[i], i + 1);
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> cards[i];
    blackjack(0, 0, 0);
    cout << result << endl;
    return 0;
}