#include <iostream>
#include <string>

using namespace std;

string divide_part(int matrix[][64], int row, int column, int N){
    if(N == 1){
        return to_string(matrix[row][column]);
    }
    
    string result = "";
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            
        }
    }
    
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

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}