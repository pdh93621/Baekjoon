#include <iostream>
#include <vector>

using namespace std;

vector<int> divide_block(int matrix[][2187], int row, int column, int N){
    vector<int> result(3,0);
    vector<int> temp;
    int num_zero = 0;
    if(N == 1){
        result[matrix[row][column] + 1] += 1;
        return result;
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            temp = divide_block(matrix, row + i * N / 3, column + j * N / 3, N / 3);
            for(int k = 0; k < 3; k++){
                result[k] += temp[k];
            }
        }
    }

    for(int n = 0; n < 3; n++){
        if(!result[n]){
            num_zero++;
        }
    }

    if(num_zero == 2){
        for(int m = 0; m < 3; m++){
            result[m] = (bool)result[m];
        }
    }

    return result;
}

int main(){
    int N;
    cin >> N;
    int matrix[2187][2187];
    vector<int> answer;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> matrix[i][j];
        }
    }

    answer = divide_block(matrix, 0, 0, N);

    for(int k = 0; k < 3; k++){
        cout << answer[k] << endl;
    }

    return 0;
}