#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

int square(pair<int, int> A, pair<int, int> B){
    return pow(A.first - B.first, 2) + pow(A.second - B.second, 2);
}

int solution(vector<pair<int, int>> coords, int N){
    int result = 0;

    return result;
}

int main(){
    int N;
    cin >> N;
    vector<pair<int, int>> coords(N);
    
    for(int i = 0; i < N; i++){
        cin >> coords[i].first;
        cin >> coords[i].second;
    }

    cout << solution(coords, N) << endl;

    return 0;
}