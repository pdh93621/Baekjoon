#include <iostream>
#define EMPTY 0
#include <string>

using namespace std;

typedef struct q{
    int n;
    q* link;
}Queue;

Queue* Getnode(){
    Queue* newA;
    newA = (Queue*)malloc(sizeof(Queue));
    newA->link = EMPTY;
    return newA;
}

bool empty(Queue** head){
    return *head == EMPTY;
}

void push(Queue** head, Queue** tail, int n){
    if(*tail){
        (*tail)->link = Getnode();
        *tail = (*tail)->link;
        (*tail)->n = n;
    }
    else{
        *tail = Getnode();
        *head = *tail;
        (*tail)->n = n;
    }
}

void pop(Queue** head, Queue** tail){
    if(*head){
        Queue* temp;
        temp = *head;
        cout << temp->n << "\n";
        if(temp == *tail) *tail = (*tail)->link;
        *head = (*head)->link;
        free(temp);
    }
    else cout << -1 << "\n";
}

int front(Queue** head){
    if(*head) return (*head)->n;
    else return -1;
}

int back(Queue** tail){
    if(*tail) return (*tail)->n;
    else return -1;
}

int size(Queue* head){
    if(head == EMPTY) return 0;
    else return 1 + size(head->link);
}

int main(){
    int N;
    Queue* head = EMPTY;
    Queue* tail = EMPTY;
    string s;
    int n;

    cin >> N;

    while(N--){
        cin >> s;
        if(s == "push"){
            cin >> n;
            push(&head, &tail, n);
        }
        else if(s == "pop") pop(&head, &tail);
        else if(s == "empty") cout << empty(&head) << "\n";
        else if(s == "front") cout << front(&head) << "\n";
        else if(s == "back") cout << back(&tail) << "\n";
        else cout << size(head) << "\n";
    }

    return 0;
}