#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> numbers){

    return 0;
}

int main(){

    int T;
    int K;
    vector<int> numbers;
    int temp;
    cin >> T;

    for(int i = 0; i < T; i++){
        cin >> K;
        for(int j = 0; j< K; j++){
            cin >> temp;
            numbers.push_back(temp);
        }
        cout << solution(numbers) << endl;
        numbers.clear();
    }

    return 0;
}