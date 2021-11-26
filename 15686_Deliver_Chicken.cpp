#include <iostream>
#include <vector>
#include <utility>

using namespace std;
int N, M;
vector<pair<int, int>> house;
vector<pair<int, int>> kfc;
int h_num;
int k_num;
int M[13];
vector<vector<int>> dist;

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

    k2h();

    return 0;
}