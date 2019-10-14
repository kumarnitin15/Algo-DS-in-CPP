#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *head;

void insert(int pos, int data){
    Node *t = new Node;
    t->data = data;
    t->next = NULL;
    
    if(pos == 1){
        t->next = head;
        head = t;
        return;
    }
    
    Node *tmp = head; int cnt = 1;
    while(tmp && cnt < pos-1){
        tmp = tmp->next;
        cnt++;
    }
   
    if(!tmp){
        cout << "Invalid position" << endl;
        return;
    }
   
    t->next = tmp->next;
    tmp->next = t;
}

bool search(int data){
    Node *tmp = head;
    while(tmp && tmp->data != data)
        tmp = tmp->next;
    if(tmp)
        return true;
    return false;
}

int main() {
    head = NULL;
    insert(1, 1);
    insert(1, 2);
    insert(2, 3);
    insert(2, 4);
    insert(3, 5);
    insert(6, 6);
    
    cout << search(3) << endl << search(7) << endl;
}
