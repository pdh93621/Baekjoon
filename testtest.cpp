#include <iostream> 
#include <queue>
#include <cmath>

using namespace std; 

int n[4][4];

int main(){
    int h = 1;
    int c = 0;
    h += !(h > c);
    c += (h > c);
    cout << h << " " << c << endl;
    return 0;
}