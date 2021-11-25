#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int N;
int dp[16][16];

void look_dp(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cout << dp[i][j] << "\t";
        }
        cout << "\n";
    }
}

int get_max(){
    int result = 0;
    for(int i = 1; i <= N; i++){
        int temp = 0;
        for(int j = 1; j <= N; j++){
            if(dp[i][j] >= 0) dp[i][j] += dp[i - 1][j];
            else dp[i][j] = max(temp, dp[i - 1][j]);
            temp = max(temp, dp[i][j]);
        }
    }
    for(int i = 1; i <= N; i++){
        result = max(result, dp[N][i]);
    }
    return result;
}

int main(){
    int temp_T;
    int temp_P;
    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> temp_T >> temp_P;
        for(int j = 1; j < i; j++) dp[j][i] = -1;
        if(i + temp_T <= N + 1) dp[i + temp_T - 1][i] = temp_P;
        for(int j = i + temp_T; j <= N; j++) dp[j][i] = -2;
    }

    cout << get_max() << endl;
}