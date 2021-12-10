#include <iostream> 
#include <queue>
#include <cmath>

using namespace std; 

typedef struct{
    int i, j;
}info;

int main(){
    
    info k = {1, 2};
    info p = k;
    cout << p.i << p.j << endl;
    return 0;
}