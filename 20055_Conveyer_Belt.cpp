#include <iostream>
#include <deque>

using namespace std;

int N, K;
deque<bool> isrobot;
deque<int> durability;

void rotate(){
    isrobot.push_front(isrobot.back());
    isrobot.pop_back();

    durability.push_front(durability.back());
    durability.pop_back();
    isrobot[N - 1] = false;
}

void move_robot(){
    for(int i = N - 2; i >= 0; i--){
        if(isrobot[i] && !isrobot[i + 1] && durability[i + 1]){
            isrobot[i] = false;
            isrobot[i + 1] = true;
            durability[i + 1]--;
        }
    }
    isrobot[N - 1] = false;
}

void put_robot(){
    if(!isrobot[0] && durability[0]){
        durability[0]--;
        isrobot[0] = true;
    }
}

int num_zero(){
    int num = 0;
    for(int i = 0; i < 2 * N; i++) if(!durability[i]) num++;
    return num;
}



int main(){
    int temp;
    int step = 0;
    cin >> N >> K;
    for(int i = 0; i < 2 * N; i++){
        cin >> temp;
        durability.push_back(temp);
        isrobot.push_back(false);
    }

    do{
        step++;
        rotate();
        move_robot();
        put_robot();

    } while(num_zero() < K);

    cout << step << endl;

    return 0;
}