#include <iostream>
#include <vector>
#include <string>

using namespace std;

string num2bin(long long B){
    string bin = "";
    while(B){
        bin = to_string(B % 2) + bin;
        B /= 2;
    }

    //cout << bin << endl;
    return bin;
}

vector<vector<int>> mat_mul(vector<vector<int>> A, vector<vector<int>> B, int N){
    vector<vector<int>> result(N);
    int temp = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                temp += A[i][k] * B[k][j];
            }
            result[i].push_back(temp % 1000);
            temp = 0;
        }
    }
    return result;
}

void print_vector(vector<vector<int>> matrix, int N){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> solution(vector<vector<int>> matrix, int N, long long B){
    vector<vector<int>> result = matrix;
    string binB = num2bin(B);

    string::iterator iter;
    for(iter = binB.begin() + 1; iter != binB.end(); iter++){
        if(*iter - '0'){
            result = mat_mul(mat_mul(result, result, N), matrix, N);
        }
        else{
            result = mat_mul(result, result, N);
        }
        //print_vector(result, N);
    }
    return result;
}

int main(){
    int N;
    long long B;
    cin >> N;
    cin >> B;
    vector<vector<int>> matrix(N,vector<int>(N));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> matrix[i][j]; 
        }
    }

    print_vector(solution(matrix, N, B), N);

    return 0;
}