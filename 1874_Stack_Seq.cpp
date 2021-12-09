#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    int n;
    cin >> n;
    int now = 1;
    stack<int> seq;
    string answer;
    
    while(n--){
        int temp;
        cin >> temp;
        
        while(now <= temp){
            seq.push(now++);
            answer += '+';
        }

        if(temp == seq.top()){
            seq.pop();
            answer += '-';
        }
        else{
            cout << "NO" << endl;
            return 0;   
        }
    }

    for(auto i : answer){
        cout << i << '\n';
    }
    return 0;
}