#include <iostream>

using namespace std;

int N, M;
int sol[9];

void dfs(int m){
    if(m == 0){
        for(int i = 1; i <= M; i++){
            cout << sol[i] << " ";
        }
        cout << "\n";
    }
    else{
        for(int i = 1; i <= N; i++){
            if(sol[M - m] <= i){
                sol[M - m + 1] = i;
                dfs(m - 1);
            }
        }
    }
}

int main(){

    cin >> N >> M;
    sol[0] = 0;
    dfs(M);

    return 0;
}