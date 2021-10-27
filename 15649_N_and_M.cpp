#include <iostream>

using namespace std;

bool visited[9];
int temp[9];
int N;
int M;

void dfs(int m){
    if (m == M){
        for(int i = 0; i < M; i++){
            cout << temp[i] << ' ';
        }
        cout << "\n";
    }
    else{
        for(int i = 1; i <= N; i++){
            if(!visited[i]){
                temp[m] = i;
                visited[i] = true;
                dfs(m + 1);
                visited[i] = false;
            }
        }
    }
}

int main(){
    cin >> N >> M;
    dfs(0);
    return 0;
}