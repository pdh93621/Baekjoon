#include <iostream>
#include <deque>
#include <stack>
#include <algorithm>

using namespace std;

typedef struct{
    int x, y, diff;
} cinfo;

int N, K;

deque<int> bowls[70];
int x_dir[2] = {-1, 0};
int y_dir[2] = {0, 1};

void look_bowls(int h){
    deque<int>::iterator iter;
    for(int i = h - 1; i >= 0; i--){
        for(iter = bowls[i].begin(); iter != bowls[i].end(); iter++) cout << *iter << "\t";
        cout << "\n"; 
    }
    cout << "\n";
}

void plus_fish(){
    int m = *min_element(bowls[0].begin(), bowls[0].end());
    for(int i = 0; i < N; i++) if(bowls[0][i] == m) bowls[0][i]++; 
}

void ctrl_fish(int h){
    int nx, ny;
    int diff;
    stack<cinfo> s;
    for(int x = h - 1; x >= 0; x--){
        for(int y = 0; y < bowls[x].size(); y++){
            for(int i = 0; i < 2; i++){
                nx = x + x_dir[i];
                ny = y + y_dir[i];
                if(nx >= 0 && ny < bowls[x].size()) {
                    diff = (bowls[x][y] - bowls[nx][ny]) / 5;
                    if(diff) {
                        s.push({x, y, -diff});
                        s.push({nx, ny, diff});
                    }
                }
            }
        }
    }
    while(!s.empty()){
        bowls[s.top().x][s.top().y] += s.top().diff;
        s.pop();
    }
}

void flat_bowl(int h, int n){
    stack<int> temp_b;
    
    while(n--){
        for(int x = 0; x < h; x++){
            temp_b.push(bowls[x].front());
            bowls[x].pop_front(); 
        }
    }

    while(!temp_b.empty()){
        bowls[0].push_front(temp_b.top());
        temp_b.pop();
    }
}

bool is_poss(int h, int n, int l){
    return (l - n >= h);
}

void first_step(){
    plus_fish();
    int h, n, l, k;
    h = 1;
    n = 0;
    l = N;
    stack<stack<int>> ss;

    while(is_poss(h, n, l)){
        for(int i = 0; i < h; i++){
            stack<int> temp;
            for(int j = 0; j < n; j++){
                temp.push(bowls[i].front());
                bowls[i].pop_front();
            }
            if(!temp.empty()) ss.push(temp);
        }
        while(!ss.empty()){
            k = 1;
            while(!ss.top().empty()){
                bowls[k].push_front(ss.top().top());
                ss.top().pop();
                k++;
            }
            ss.pop();
        }
        l -= n;
        if(h > n) n++;
        else h++;
        //cout << h << n << endl;
        //look_bowls(h);
    }
    ctrl_fish(h);
    //look_bowls(h);
    flat_bowl(h, n);
    //look_bowls(1);
}

void second_step(){
    int n = N / 2;
    stack<int> s;
    while(n--) {
        bowls[1].push_front(bowls[0].front());
        bowls[0].pop_front();
    }
    n = N / 4;

    while(n--){
        bowls[2].push_front(bowls[1].front());
        bowls[1].pop_front();
        bowls[3].push_front(bowls[0].front());
        bowls[0].pop_front();
    }

    ctrl_fish(4);
    //look_bowls(4);
    flat_bowl(4, N / 4);
    //look_bowls(1);
}

int main(){
    cin >> N >> K;
    int fish;
    int time = 0;
    for(int i = 0; i < N; i++){
        cin >> fish;
        bowls[0].push_back(fish);
    }

    while(++time) {
        first_step();
        second_step();
        if(*max_element(bowls[0].begin(), bowls[0].end()) - *min_element(bowls[0].begin(), bowls[0].end()) <= K) break;
    }

    cout << time << endl;

    return 0;
}