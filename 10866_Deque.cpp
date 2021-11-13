#include <iostream>
#define EMPTY 0

using namespace std;

typedef struct Deque{
    int num;
    Deque* link;
}deque;

deque* Getnode(){
    deque* New;
    New = (deque*)malloc(sizeof(deque));
    New->link = EMPTY;
    return New;
}

bool empty(deque** head){
    if(*head == EMPTY){
        return true;
    }
    return false;
}

void push_front(deque** head, deque** tail, int n){
    if(*head){
        deque* temp = *head;
        *head = Getnode();
        (*head)->link = temp;
        (*head)->num = n;
    }
    else{
        *head = Getnode();
        *tail = *head;
        (*head)->num = n;
    }
}

void push_back(deque** head, deque** tail, int n){
    if(*tail){
        (*tail)->link = Getnode();
        *tail = (*tail)->link;
        (*tail)->num = n;
    }
    else{
        *tail = Getnode();
        *tail = *head;
        (*tail)->num = n;
    }
}

void front(deque** head){
    if(*head){
        cout <<  (*head)->num << "\n";
    }
    else{
        cout << -1 << "\n";
    }
}

void back(deque** tail){
    if(*tail){
        cout << (*tail)->num << "\n";
    }
    else{
        cout << -1 << "\n";
    }
}

void pop_front(deque** head){
    if(*head){
        deque* temp;
        temp = *head;
        cout << temp->num << "\n";
        *head = (*head)->link;
        free(temp);
    }
    else{
        cout << -1 << "\n";
    }
}

void pop_back(deque** tail){
    if(*tail){
        cout << (*tail)->num << "\n";
    }
    else{
        cout << -1 << "\n";
    }
}

int size(deque** head, deque** tail){

}



int main(){

    deque* Head = EMPTY;
    deque* Tail = EMPTY;

    cout << empty(&Head) << endl;

    return 0;
}