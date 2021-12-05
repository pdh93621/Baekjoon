#include <iostream>

using namespace std;

int N;

long long gcd(long long a, long long b){
    if(a % b){
        return gcd(b, a % b);
    }
    else return b;
}

int main(){
    long long a, b;
    cin >> N;
    while(N--){
        cin >> a >> b;
        cout << a * b / gcd(max(a, b), min(a, b)) << "\n";
    }

    return 0;
}