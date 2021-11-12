#include <iostream>
#include <string>
#include <stack>

using namespace std;



int is_bracket(char s){
    char brackets[4] = {'(', ')', '[', ']'};
    for(int i = 0; i < 4; i++){
        if(s == brackets[i]) return i;
    }
    return -1;
}

bool solution(string str){
    stack<int> k;

    for(auto s: str){
        int temp = is_bracket(s);
        if(temp >= 0){
            
            if(k.empty()){
                if(temp % 2){
                    return false;
                }
                else{
                    k.push(temp);
                }
            }
            else{
                int t = temp;
                temp += k.top();
                if(temp % 2){
                    if(temp == 3){
                        return false;
                    }
                    else{
                        k.pop();
                    }
                }
                else{
                    k.push(t);
                }
            }
        }
    }

    return k.empty();
}

int main(){
    string str;
    while(1){
        getline(cin, str);
        
        if(str == "."){
            break;
        }
        
        if(solution(str)){
            cout << "yes" << "\n";
        }
        else{
            cout << "no" << "\n";
        }
    }
    return 0;
}