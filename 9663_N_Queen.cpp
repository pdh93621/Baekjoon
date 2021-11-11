#include <iostream>

using namespace std;
int N;
int result;
int col[16];

bool not_meet(int n, int i){
    for(int j = 1; j < n; j++){
        if(col[n - j] == i || abs(col[n - j] - i) == j){
            return false;
        }
    }
    return true;
}

void dfs(int n){
    if(n > N){
        result++;
        return;
    }

    for(int i = 1; i <= N; i++){
        if(not_meet(n, i)){
            col[n] = i;
            dfs(n + 1);
        }
    }
}

int main(){
    cin >> N;

    dfs(1);

    cout << result << endl;    

    return 0;
}