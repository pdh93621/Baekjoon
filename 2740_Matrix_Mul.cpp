#include <iostream>

using namespace std;

int main(){
    int A[100][100] = {0,};
    int B[100][100] = {0,};
    int temp = 0;

    int N, M, K;
    cin >> N;
    //cout << N << endl;
    cin >> M;
    //cout << M << endl;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> A[i][j];
            //cout << "("<< i << ", " << j << ")";
        }
        //cout << endl;
    }

    cin >> M; 
    //cout << M << endl;
    cin >> K;
    //cout << K << endl;

    for(int i = 0; i < M; i++){
        for(int j = 0; j < K; j++){
            cin >> B[i][j];
            //cout << "("<< i << ", " << j << ")";
        }
    }

    for(int n = 0; n < N; n++){
        for(int k = 0; k < K; k++){
            for(int m = 0; m < M; m++){
                temp += A[n][m] * B[m][k];
            }
            cout << temp << " ";
            temp = 0;
        }
        cout << endl;
    }

    return 0;
}