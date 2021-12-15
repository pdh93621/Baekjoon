#include <iostream>
#include <list>

using namespace std;

typedef struct{
    int i, j;
}go;

int main(){
    list<go> k;
    k.push_back({1, 2});
    k.push_back({2, 2});
    k.push_back({3, 2});
    k.push_back({4, 2});
    k.push_back({2, 2});
    k.push_back({4, 2});

    list<go>::iterator iter;
    for(iter = k.begin(); iter != k.end(); iter++){
        if((*iter).i == 2){
            k.erase(iter);
            break;
        } 
    }

    for(iter = k.begin(); iter != k.end(); iter++) cout << (*iter).i << (*iter).j << endl;

    return 0;
}