#include <iostream>
#include <vector>

using namespace std;

int x_dir[4] = {1, 0, -1, 0};
int y_dir[4] = {0, -1, 0, 1};

vector<int> directions;
int generation[11] = {0,};
bool plane[101][101];

void get_dir(int current_g){
    int temp = generation[current_g - 1] - 1;
    int n = 0;
    while(n <= temp){
        directions.push_back((directions[temp - n] + 1) % 4);
        n++;
    }
    generation[current_g] = 2 * temp + 2;
}

void make_generation(int m){

    for(int i = 1; i <= m; i++){
        if(!generation[i]){
            get_dir(i);
        }            
    }
}

void dot_plane(int x, int y, int d, int g){
    int end_x = x;
    int end_y = y;
    plane[y][x] = true;
    for(int i = 0; i < generation[g]; i++){
        end_x += x_dir[(d + directions[i]) % 4];
        end_y += y_dir[(d + directions[i]) % 4];
        plane[end_y][end_x] = true;
    }
}

int main(){

    int N;
    cin >> N;
    int result = 0;

    int x,y,d,g;
    directions.push_back(0);
    generation[0] = 1;

    for(int i = 0; i < N; i++){
        cin >> x >> y >> d >> g;
        make_generation(g);
        dot_plane(x, y, d, g);
    }

    for(int j = 0; j < 100; j++){
        for(int k = 0; k < 100; k++){
            if(plane[j][k] && plane[j + 1][k] && plane[j][k + 1] && plane[j + 1][k + 1]){
                result += 1;
            }
        }
    }

    cout << result << endl;
    return 0;
}