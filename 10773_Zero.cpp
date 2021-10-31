#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<int> s;
    int K;
    int temp;
    int result = 0;
    cin >> K;

    for(int i = 0; i < K; i++){
        cin >> temp;
        if (temp){
            s.push(temp);
        }
        else{
            s.pop();
        }
    }

    while(!s.empty()){
        temp = s.top();
        result += temp;
        s.pop();
    }

    cout << result << "\n";

    return 0;
}