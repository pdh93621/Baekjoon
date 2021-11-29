#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int N;
int area[100][100];
int arrow[101];
vector<vector<pair<int, int>>> height(1);

int result = 1;
int x_dir = {-1, 0, 1, 0};
int y_dir = {0, 1, 0, -1};

void bfs(int x, int y){
    int nx, ny;
        
}

int main(){
    int h = 1;
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> area[i][j];
            if(!arrow[area[i][j]]){
                vector<pair<int, int>> temp;
                temp.push_back({i, j});
                arrow[area[i][j]] = h;
                height.push_back(temp); 
            }
            else height[arrow[area[i][j]]].push_back({i, j});
        } 
    }

    return 0;
}