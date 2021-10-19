#include <iostream>
#include <utility>

using namespace std;

pair<int, int> solution(int matrix[128][128], int N){
    pair<int, int> result = make_pair(0, 0);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return result;
}

int main(){
    int matrix[128][128] = {0,};
    int N;
    pair<int, int> answer;
    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> matrix[i][j];
        }
    }

    answer = solution(matrix, N);

    cout << answer.first << " " << answer.second << endl;

    return 0;
}