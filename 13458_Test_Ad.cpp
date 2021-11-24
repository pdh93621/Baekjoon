#include <iostream>
#include <queue>

using namespace std;
int N;
queue<int> classes;
int B, C;

int main(){
    int A;
    long long result = 0;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A;
        classes.push(A);
    }

    cin >> B >> C;

    while(!classes.empty()){
        A = classes.front();
        classes.pop();
        result++;
        if(A > B) A -= B;
        else A = 0;

        if(A % C) result++;
        result += A / C;
    }

    cout << result << endl;

    return 0;
}