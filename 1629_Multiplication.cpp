#include <iostream>

using namespace std;

int divide_num(int A, int B, int C){
    if (B > 1){
        long long temp = divide_num(A, B / 2, C);
        if (B % 2){
            return ((temp * temp) % C * A) % C;
        }
        else{
            return (temp * temp) % C;
        }
    }
    else{
        return A;
    }
}
int main(){
    int A, B, C;
    cin >> A;
    cin >> B;
    cin >> C;

    cout << divide_num(A % C, B, C) << endl;

    return 0;
}