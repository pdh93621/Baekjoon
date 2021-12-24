#include <iostream> 
#include <queue>
#include <cmath>
#include <deque>

using namespace std; 

int n[4][4];

int main(){
    
    deque<int> d;
    d.push_back(0);
    d.push_back(1);
    d.push_back(2);

    d.back()++;

    cout << d.back() << endl;
    
    return 0;
}