#include <iostream>
#include <queue>

using namespace std;

typedef struct{
    int r, c;
} RC;

typedef struct{
    int m, s, d;
} state;

typedef struct{
    RC rc;
    state st;
} info;

typedef struct{
    int size = 0;
    queue<state> states;
} board;

int N, M, K;

queue<info> fires;
queue<RC> locations;
board B[50][50];

int x_dir[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int y_dir[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void look_B(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cout << B[i][j].size << " ";
        cout << "\n";
    }
    cout << "\n";
}

void look_fires(){
    if(fires.empty()) cout << "empty" << "\n";
    else{    
        int fz = fires.size();
        while(fz--){
            cout << fires.front().rc.r << fires.front().rc.c << " ";
            fires.push(fires.front());
            fires.pop();
        }
        cout << "\n";
    }
}

int penet(int n){
    if(n >= N) return n - N;
    else if(n < 0) return n + N;
    else return n;
}

info move_fire(info fire){
    fire.rc = {penet(fire.rc.r + fire.st.s * x_dir[fire.st.d]), penet(fire.rc.c + fire.st.s * y_dir[fire.st.d])};
    return fire;
}

void move_all(){
    RC rc;
    state st;
    info fire;
    int temp_m;
    int temp_s;
    bool multi;
    bool addit;
    bool oe;

    // 불꽃 이동
    while(!fires.empty()){
        fire = move_fire(fires.front());
        rc = fire.rc;
        st = fire.st;
        fires.pop();
        if(!B[rc.r][rc.c].size) locations.push(rc);
        B[rc.r][rc.c].size++;
        B[rc.r][rc.c].states.push(st);
    }

    //look_B();
    //look_fires();

    // 불꽃 나누기
    while(!locations.empty()){
        rc = locations.front();
        locations.pop();
        if(B[rc.r][rc.c].size == 1) {
            fire.rc = rc;
            fire.st = B[rc.r][rc.c].states.front();
            B[rc.r][rc.c].states.pop();
            fires.push(fire);
        }
        else if(B[rc.r][rc.c].size > 1) {
            //홀수 판별
            multi = true;
            //짝수 판별
            addit = false;
            temp_m = 0;
            temp_s = 0;
            while(!B[rc.r][rc.c].states.empty()){
                st = B[rc.r][rc.c].states.front();
                B[rc.r][rc.c].states.pop();
                temp_m += st.m;
                temp_s += st.s;
                multi *= st.d % 2;
                addit += st.d % 2;
            }
            temp_m /= 5;

            //질량이 0이되면 소멸
            if(temp_m > 0){
                temp_s /= B[rc.r][rc.c].size;
                oe = (multi != addit);
                for(int i = 0; i < 4; i++) fires.push({rc.r, rc.c, temp_m, temp_s, 2 * i + oe});
            }
        }
        B[rc.r][rc.c].size = 0;
    }
    //look_B();
    //look_fires();
}

int main(){
    int r, c, m, s, d;
    int total = 0;
    cin >> N >> M >> K;
    
    for(int i = 0; i < M; i++){
        cin >> r >> c >> m >> s >> d;
        fires.push({r - 1, c - 1, m, s % N, d});
    }

    while(K--) move_all();

    while(!fires.empty()){
       total += fires.front().st.m;
        fires.pop();
    }

    cout << total << endl;

    return 0;
}