#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int N, L;
int map[100][100];
bool x_dir[2] = {0, 1};
bool y_dir[2] = {1, 0};

bool check_line(int n, bool dir){
    int x = n * x_dir[dir];
    int y = n * y_dir[dir];
    vector<pair<int, int>> line;
    pair<int, int> temp = make_pair(map[x][y], 1);
    for(int i = 1; i < N; i++){
        int pre = map[x + (i - 1) * y_dir[dir]][y + (i - 1) * x_dir[dir]];
        int now = map[x + i * y_dir[dir]][y + i * x_dir[dir]];
        if(pre == now) temp.second++;
        else{
            if(abs(pre - now) > 1) return false;
            line.push_back(temp);
            temp = make_pair(now, 1);
        }
    }
    line.push_back(temp);
    for(int i = 0; i < line.size() - 1; i++){
        if(line[i] > line[i + 1]){
            if(line[i + 1].second < L) return false;
            else line[i + 1].second -= L;
        }
        else{
            if(line[i].second < L) return false;
            else line[i].second -= L;
        }
    }
    //cout << n << " " << dir << "\n";
    return true;
}

int main(){
    int result = 0;
    int n = 0;
    cin >> N >> L;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }    
    
    while(n != N){
        result += check_line(n, 0) + check_line(n, 1);
        n++;
    }

    cout << result << endl;
    return 0;
}