#include <iostream>
#include <string>
#include <stack>
#include <stdlib.h>

using namespace std;

int main(){

    int N;
    stack<int> S;
    string order;
    char temp;
    cin >> N;

    for(int i = 0; i <= N; i++){
        getline(cin, order);
        temp = order[0];
        if(temp == 'p'){
            if(order[1] == 'u'){
                string::iterator iter;
                string num;
                for(iter = order.begin() + 5; iter != order.end(); iter++){
                    num += *iter;
                }
                S.push(stoi(num));
            }
            else{
                if(S.empty()){
                    cout << -1 << "\n";
                }
                else{
                    cout << S.top() << "\n";
                    S.pop();
                }
            }
        }
        else if(temp == 't'){
            if(S.empty()){
                cout << -1 << "\n";
            }
            else{
                cout << S.top() << "\n";
            }
            
        }
        else if(temp == 's'){
            cout << S.size() << "\n";
        }
        else if(temp == 'e'){
            cout << S.empty() << "\n";
        }
    }

    return 0;
}