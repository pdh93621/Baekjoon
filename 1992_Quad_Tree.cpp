#include <iostream>
#include <string>

using namespace std;

string divide_part(int matrix[][64], int row, int column, int N){
    if(N == 1){
        return to_string(matrix[row][column]);
    }
    
    string result = "";
    string temp;
    
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            temp = divide_part(matrix, row + i * N / 2, column + j * N / 2, N / 2);
            result += temp;
        }
    }

    if(result == "1111" || result == "0000"){
        string a = ""; 
        a.push_back(result[0]);
        return a;
    }

    return "(" + result + ")";
}

int main(){
    int N;
    cin >> N;
    string temp;
    int matrix[64][64];
    for(int i = 0; i < N; i++){
        cin >> temp;
        for(int j = 0; j < N; j++){
            matrix[i][j] = temp[j] - '0';
        }
    }

    cout << divide_part(matrix, 0 , 0, N) << endl;

    return 0;
}