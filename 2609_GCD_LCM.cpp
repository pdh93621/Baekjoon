#include <iostream>

using namespace std;

int gcd(int small, int big){
    int rest = big % small;
    if(rest){
        return gcd(rest, small);
    }
    else{
        return small;
    }
}

int main(){
    int N, M;    
    cin >> N >> M;
    
    int GCD = gcd(min(N, M), max(N, M));
    cout << GCD << endl;
    cout << N / GCD * M << endl;

    return 0;
}