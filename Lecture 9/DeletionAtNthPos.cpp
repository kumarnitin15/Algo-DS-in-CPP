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

void remove(int pos){
    Node *tmp = head;

    if(!head){
        cout << "Underflow" << endl;
        return;
    }
    
    if(pos == 1)
        head = head->next;
    
    else {
        int cnt = 1;
        while(tmp && cnt < pos-1){
            tmp = tmp->next;
            cnt++;
        }
        if(!tmp || !tmp->next){
            cout << "Underflow" << endl;
            return;
        }
        Node *t = tmp->next;
        tmp->next = tmp->next->next;
        tmp = t;
    }
    delete tmp;
}

void display(){
    Node *tmp = head;
    while(tmp){
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main() {
    head = NULL;
    insert(1, 1);
    insert(1, 2);
    insert(2, 3);
    insert(2, 4);
    insert(3, 5);
    insert(6, 6);
    display();

    remove(3);
    display();

    remove(2);
    display();

    remove(1);
    display();

    remove(3);
    display();
}
