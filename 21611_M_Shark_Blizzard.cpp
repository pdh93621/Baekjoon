#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int N, M;
int sx, sy;
int marble[49][49];
int numbering[49][49];

queue<int> m;
queue<int> destroyd;

int nx_dir[4] = {0, 1, 0, -1};
int ny_dir[4] = {-1, 0, 1, 0};
int x_dir[4] = {-1, 1, 0, 0};
int y_dir[4] = {0, 0, -1, 1};

int score;

void look_m(){
    int s = m.size();
    while(s--){
        cout << m.front() << " ";
        m.push(m.front());
        m.pop();
    }
    cout << "\n";
}

void make_numbering(){
    int n = 1;
    int k = 0;
    int x = N / 2;
    int y = N / 2;
    int d = 0;

    while(true) {
        for(int i = 0; i < k / 2 + 1; i++){
            x += nx_dir[d];
            y += ny_dir[d];
            if(x < 0) return;
            numbering[x][y] = n++;
            
            if(marble[x][y]) m.push(marble[x][y]);     
        }
        d = (d + 1) % 4;
        k++;
    }
}

void select_destroy(int d, int s){
    int nx, ny;
    for(int i = 1; i <= s; i++){
        nx = sx + i * x_dir[d - 1];
        ny = sy + i * y_dir[d - 1];
        destroyd.push(numbering[nx][ny]);
    }
}

void destroy_all(){
    int num = 0;
    int s = m.size();
    int d = destroyd.front();
    destroyd.pop();

    while(num++ != s){
        if(num > N * N - 1) {
            m.pop();
            continue;
        }
        
        if(num == d) {
            m.pop();
            if(destroyd.empty()) d = -1;
            else {
                d = destroyd.front();
                destroyd.pop();
            }
            continue;
        }

        m.push(m.front());
        m.pop();
    }

    while(!destroyd.empty()) destroyd.pop();
}

bool destroy7boom(){
    int num = 0;
    int succeed = 1;
    int s = m.size();
    bool is_boom = false;

    if(!s) return false;

    queue<int> temp;

    while(num++ != s){

        if(!temp.empty()) {
            if(temp.back() == m.front()) succeed++;
            else {
                if(succeed < 4) {
                    while(!temp.empty()) {
                        m.push(temp.front());
                        temp.pop();
                    }
                }
                else {
                    score += succeed * temp.front();
                    while(!temp.empty()) temp.pop();
                    is_boom = true;
                }
                succeed = 1;
            }
        }

        temp.push(m.front());
        m.pop();
    }

    if(temp.size() >= 4) {
        score += temp.size() * temp.front();
        is_boom = true;
    }
    else {
        while(!temp.empty()){
            m.push(temp.front());
            temp.pop();
        }
    }

    return is_boom;
}

void transform(){
    int num = 0;
    int succeed = 1;
    int s = m.size();

    queue<int> temp;

    while(num++ != s){

        if(!temp.empty()) {
            if(temp.back() == m.front()) succeed++;
            else {
                m.push(succeed);
                m.push(temp.front());
                succeed = 1;
                while(!temp.empty()) temp.pop();
            }
        }

        temp.push(m.front());
        m.pop();
    }

    if(temp.size()) {
        m.push(temp.size());
        m.push(temp.front());
    }
}

int main() {
    int d, s;
    cin >> N >> M;
    sx = N / 2;
    sy = N / 2;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cin >> marble[i][j];
    }

    make_numbering();

    while(M--){
        cin >> d >> s;
        select_destroy(d, s);
        destroy_all();
        //cout << m.size() << endl;
        while(destroy7boom());
        transform();
    }
    //look_m();
    cout << score << endl;

    return 0;
}