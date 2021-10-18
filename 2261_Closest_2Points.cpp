#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<pair<int, int>> coords(N);
    
    for(int i = 0; i < N; i++){
        cin >> coords[i].first;
        cin >> coords[i].second;
    }

    cout << coords[0].first << coords[0].second << endl;

    return 0;
}