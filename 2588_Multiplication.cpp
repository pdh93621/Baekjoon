#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(){
    int num1;
    int num2;

    cin >> num1;    
    cin >> num2;

    string str = to_string(num2);

    for(int i = 2; i >= 0; i--){
        cout << int(str[i] - '0') * num1 << endl;
    }

    cout << num1 * num2 << endl;

    return 0;
}
