#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    char brakets[4] = {'(', ')', '[', ']'};
    string str;

    while(1){
        stack<char> sta;
        getline(cin, str);

        if(str == "."){
            break;
        }

        for(auto s : str){
            for(auto i : brakets){
                if(s == i){
                    
                }
            }
        }
    }

    return 0;
}