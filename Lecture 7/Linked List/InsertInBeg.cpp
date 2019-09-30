#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *head = NULL;

void insert(int data){
    Node *tmp = new Node;
    tmp->data = data;
    tmp->next = NULL;

    if(head == NULL)
        head = tmp;

    else {
        tmp->next = head;
        head = tmp;
    }
}

void printList(){
    Node *tmp = head;
    while(tmp!=NULL){
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main() {
    insert(2);
    printList();
    insert(5);
    printList();
    insert(3);
    printList();
    insert(6);
    printList();
}
