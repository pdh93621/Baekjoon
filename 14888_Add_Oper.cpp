#include <iostream>

using namespace std;
int N;
int oper[4];
int A[11];
int Min = 1000000000;
int Max = -1000000000;
int temp = 0;

int calculator(int i, int n, int m){
    switch (i)
    {
    case 0:
        return n + m;
    case 1:
        return n - m;
    case 2:
        return n * m;
    case 3:
        return n / m;
    }
}

void dfs(int n){
    if(n == 0){
        if(temp < Min){
            Min = temp;
        }

        if(temp > Max){
            Max = temp;
        }
    }
    else{
        for(int i = 0; i < 4; i++){
            if(oper[i]){
                int t;
                oper[i] -= 1;
                t = temp;
                temp = calculator(i, temp, A[N - n]);
                dfs(n - 1);

                temp = t;
                oper[i] += 1;
            }
        }
    }
}

int main(){

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    for(int j = 0; j < 4; j++){
        cin >> oper[j];
    }

    temp = A[0];

    dfs(N - 1);

    cout << Max << endl;
    cout << Min << endl;

    return 0;
}