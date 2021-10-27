#include <iostream>

using namespace std;

int N, M;
int sol[8]; 

void dfs(int m){
    if(m == 0){
        for(int i = 0; i < M; i++){
            cout << sol[i] << " ";
        }
        cout << "\n";
    }
    else{
        for(int i = 1; i <= N; i++){
        sol[M - m] = i;
        dfs(m - 1);
        }
    }
}

int main(){

    cin >> N >> M;
    dfs(M);

    return 0;
}