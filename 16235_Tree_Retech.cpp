#include <iostream>
#include <deque>
#include <algorithm>
#include <stack>

using namespace std;

typedef struct{
    int x, y, z;
    bool dead;
}info;

int N, M, K;
int A[10][10];
int ing[10][10];

int x_dir[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int y_dir[8] = {0, -1, -1, -1, 0, 1, 1, 1};

deque<info> trees;

void look_trees(){
    for(int i = 0; i < trees.size(); i++){
        cout << trees[i].z << endl;
    }
}

bool comp(info tree1, info tree2){
    return tree1.z < tree2.z;
}

void spring(){  
    for(int i = 0; i < M; i++){
        info tree = trees[i];
        if(ing[tree.x][tree.y] >= tree.z) {
            ing[tree.x][tree.y] -= tree.z;
            tree.z++;
        }
        else tree.dead = true;

        trees[i] = tree;
    }
}

void summer(){
    while(M--){
        info tree = trees.front();
        trees.pop_front();
        if(tree.dead) ing[tree.x][tree.y] += tree.z / 2;
        else trees.push_back(tree);
    }
    M = trees.size();
}   

void autumn(){
    stack<info> new_trees;
    int nx, ny;
    for(int i = 0; i < M; i++){
        info tree = trees[i];
        if(!(tree.z % 5)) {
            for(int j = 0; j < 8; j++){
                nx = tree.x + x_dir[j];
                ny = tree.y + y_dir[j];
                if(nx >= 0 && ny >= 0 && nx < N && ny < N) new_trees.push({nx, ny, 1, false});
            }
        }
    }
    while(!new_trees.empty()){
        trees.push_front(new_trees.top());
        new_trees.pop();
    }
    M = trees.size();
}

void winter(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) ing[i][j] += A[i][j];
    }
}

int main(){
    int x, y, z;
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> A[i][j];
            ing[i][j] = 5;
        }
    }
    
    for(int i = 0; i < M; i++){
        cin >> x >> y >> z;
        trees.push_back({x - 1, y - 1, z, false});
    }
    sort(trees.begin(), trees.end(), comp);

    while(K--){
        spring();
        summer();
        autumn();
        winter();
    }

    cout << M << endl;
    return 0;
}