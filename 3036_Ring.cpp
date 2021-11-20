#include <iostream>

using namespace std;

int GCD(int a, int b){
    if(!b){
        return a;
    }

    return GCD(b, a - b * (a / b));
}

int main(){
    int N;
    int A;
    int temp;
    int gcd;

    cin >> N;
    cin >> A;
    for(int i = 1; i < N; i++){
        cin >> temp;
        gcd = GCD(A, temp);

        cout << A / gcd << '/' << temp / gcd << '\n';
    }
    return 0;
}