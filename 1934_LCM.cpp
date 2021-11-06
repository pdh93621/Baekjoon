#include <iostream>

using namespace std;

int GCD(int small, int big){
    int temp = big % small;
    if(temp){
        return GCD(temp, small);
    }
    else{
        return small;
    }
}

int main(){
    int T;
    int A,B;
    cin >> T;

    for(int i = 0; i < T; i++){
        cin >> A;
        cin >> B;
        cout << A / GCD(min(A, B), max(A, B)) * B << "\n";
    }
    
    return 0;
}