#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int r, c, k;
int A[100][100];
int visited[101];
int R = 3;
int C = 3;

void look_A(){
    cout << "\n";
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++) cout << A[i][j] << "\t";
        cout << "\n";
    }
}

void R_ope(){
    int temp;
    int num = 1;
    int v_size = 0;
    int max_size = 0;
    
    for(int i = 0; i < R; i++){
        vector<pair<int, int>> subs;
        subs.push_back({0, 0});
        for(int j = 0; j < C; j++){
            temp = A[i][j];
            if(!temp) continue;
            if(visited[temp]) subs[visited[temp]].first++;
            else{
                visited[temp] = num++;
                subs.push_back({1, temp});
            }
            A[i][j] = 0;
        }
        
        sort(subs.begin(), subs.end());
        
        for(int j = 1; j < subs.size(); j++){
            visited[subs[j].second] = 0;
            A[i][2 * j - 2] = subs[j].second;
            A[i][2 * j - 1] = subs[j].first;
            v_size += 2;
            if(v_size == 100) break;
        }

        max_size = max(max_size, v_size);
        num = 1;
        v_size = 0;
    }
    C = max_size;
}

void C_ope(){
    int temp;
    int num = 1;
    int v_size = 0;
    int max_size = 0;
    
    
    for(int i = 0; i < C; i++){
        vector<pair<int, int>> subs;
        subs.push_back({0, 0});
        for(int j = 0; j < R; j++){
            temp = A[j][i];
            if(!temp) continue;
            if(visited[temp]) subs[visited[temp]].first++;
            else{
                visited[temp] = num++;
                subs.push_back({1, temp});
            }
            A[j][i] = 0;
        }

        sort(subs.begin(), subs.end());

        for(int j = 1; j < subs.size(); j++){
            visited[subs[j].second] = 0;
            A[2 * j - 2][i] = subs[j].second;
            A[2 * j - 1][i] = subs[j].first;
            v_size += 2;
            if(v_size == 100) break;
        }

        max_size = max(max_size, v_size);
        num = 1;
        v_size = 0;
    }
    R = max_size;
}

int solution(int i){
    if(i > 100) return -1;
    if(A[r][c] == k) return i;

    if(R >= C) R_ope();
    else C_ope();
    return solution(i + 1);
}

int main(){
    cin >> r >> c >> k;
    r--;
    c--;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++) cin >> A[i][j];
    }
    //look_A();
    cout << solution(0) << endl;

    return 0;
}