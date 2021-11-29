#include <iostream>

using namespace  std;

int main(){
    int N, K;
    cin >> N >> K;
    int dp[11] = {1,};

    for(int i = 1; i <= N; i++) dp[i] = dp[i - 1] * i;

    cout << dp[N] / dp[K] / dp[N - K] << endl;

    return 0;
}