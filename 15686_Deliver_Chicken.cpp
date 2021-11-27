#include <iostream>
#include <vector>
#include <utility>

using namespace std;
int N, M;
vector<pair<int, int>> house;
vector<pair<int, int>> kfc;
int h_num;
int k_num;
int selection[14] = {0,};
vector<vector<int>> dist;
int result = 10001;

int get_distance(pair<int, int> k, pair<int, int> h) {
    return abs(h.first - k.first) + abs(h.second - k.second);
}

void k2h(){
    vector<int> temp;
    for(int i = 0; i < k_num; i++){
        for(int j = 0; j < h_num; j++) temp.push_back(get_distance(kfc[i], house[j]));
        dist.push_back(temp);
        temp.clear();
    }
}

void sigma_k2h(int n){
    if(n == M + 1){
        int temp;
        int sigma = 0;
        for(int j = 0; j < h_num; j++){
            temp = 101;
            for(int i = 1; i <= M; i++){
                temp = min(temp, dist[selection[i]][j]);
            }
            sigma += temp;
        }
        result = min(sigma, result);
    
        return;
    }

    for(int i = selection[n - 1] + 1; i < k_num; i++){
        selection[n] = i;
        sigma_k2h(n + 1); 
    }
}

int main(){
    int temp;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> temp;
            if(temp == 1) house.push_back(make_pair(i, j));
            else if(temp == 2) kfc.push_back(make_pair(i, j));
        }
    }
    h_num = house.size();
    k_num = kfc.size();

    selection[0] = -1;

    k2h();

    sigma_k2h(1);

    cout << result << endl;
    return 0;
}