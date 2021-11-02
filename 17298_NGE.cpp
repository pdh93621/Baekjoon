#include <iostream>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

int main(){
    int N;
    cin >> N;
    stack<pair<int, int>> s;
    vector<int> nga(N);
    int temp_n;

    for(int i = 0; i < N; i++){
        cin >> temp_n;
        while(!s.empty() && s.top().second < temp_n){
            nga[s.top().first] = temp_n;
            s.pop();
        }
        s.push(make_pair(i, temp_n));
    }

    while(!s.empty()){
        nga[s.top().first] = -1;
        s.pop();
    }

    for(auto i : nga){
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}