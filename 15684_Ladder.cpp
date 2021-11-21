#include <iostream>
#include <stack>
#include <utility>

using namespace std;

int N, M, H;
int ladder[32][12];
stack<pair<int, int>> add_hori;
int result = 4;

void look_ladder(){
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= N; j++){
            cout << ladder[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int down_ladder(int i){
    int h = 1;
    while(h <= H){
        i += ladder[h][i];
        h++;
    }
    return i;
}

void make_hori(int a, int b){
    ladder[a][b] = 1;
    ladder[a][b + 1] = -1;
}

void reduce_hori(int a, int b){
    ladder[a][b] = 0;
    ladder[a][b + 1] = 0;
}

bool igoi(){
    for(int i = 1; i <= N; i++){
        if(i != down_ladder(i)) return false;
    }
    return true;
}

void solution(int a){
    if(a == 0){
        if(igoi()){
            result = 0;
            return;
        }
        else{
            solution(1);
            return;
        }
    }

    if(a >= result) return;
    pair<int, int> temp;
    bool add_ok = true;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= H; j++){
            if(ladder[j][i] || ladder[j][i + 1]){
                add_ok = true;
            }
            else{
                temp = make_pair(j, i);
                if(add_hori.top() < temp){
                    if(add_ok){
                        add_ok = true;
                        make_hori(j, i);
                        add_hori.push(temp);
                        
                        if(igoi()){
                            result = min(a, result);
                            reduce_hori(add_hori.top().first, add_hori.top().second);
                            add_hori.pop();
                            return;
                        }

                        solution(a + 1);
                        
                        reduce_hori(add_hori.top().first, add_hori.top().second);
                        add_hori.pop();
                    }
                }
            }
        }
    }
}

int main(){

    cin >> N >> M >> H;
    int a, b;

    add_hori.push(make_pair(0, 0));

    for(int i = 0; i < M; i++){
        cin >> a >> b;
        make_hori(a, b);
    }

    solution(0);

    if(result == 4) result = -1;
    
    cout << result << endl;

    return 0;
}