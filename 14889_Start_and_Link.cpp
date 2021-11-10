#include <iostream>

using namespace std;

int N;
int state[21][21] = {0,};
int team1[11];
int team2[11];
bool people[21];
int m = 2000;

void dfs(int n){
    if(n == 0){
        int temp = 1;
        int t1 = 0;
        int t2 = 0;
        for(int p = 1; p <= N; p++){
            if(!people[p]){
                team2[temp] = p;
                temp++;
            }
        }

        for(int i = 1; i <= N/2; i++){
            for(int j = i + 1; j <= N/2; j++){
                t1 += state[team1[i]][team1[j]] + state[team1[j]][team1[i]];
                t2 += state[team2[i]][team2[j]] + state[team2[j]][team2[i]]; 
            }
        }

        m = min(m, (int)abs(t1 - t2));
        return;
    }

    for(int i = 1; i <= N; i++){
        if(team1[N/2 - n] < i){
            team1[N/2 - n + 1] = i;
            people[i] = true;
            dfs(n - 1);
            people[i] = false;
        }
    }
}

int main(){

    cin >> N;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> state[i][j];
        }
    }

    dfs(N/2);    

    cout << m << endl;

    return 0;
}