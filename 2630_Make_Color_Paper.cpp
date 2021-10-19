#include <iostream>
#include <utility>

using namespace std;

pair<int, int> divide_blocks(int matrix[][128], int row, int column, int n){

    if(n == 1){
        return make_pair(!matrix[row][column], matrix[row][column]);
    }
    
    pair<int, int> result = make_pair(0, 0);
    pair<int, int> temp;

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            temp = divide_blocks(matrix, row + i * n / 2, column + j * n / 2, n / 2);
            result.first += temp.first;
            result.second += temp.second;
        }
    }

    //cout << n << " " << "1st: " << result.first << " " << "2nd: " << result.second <<endl;

    if(!(result.first * result.second)){
        return make_pair((bool)result.first, (bool)result.second);
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

    answer = divide_blocks(matrix, 0, 0, N);

    cout << answer.first << endl;
    cout << answer.second << endl;

    return 0;
}