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

void display(){
    Node *tmp = head;
    while(tmp) {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

Node *reverse (Node *head, int k, bool toggle) 
{ 
	if(toggle){
        Node* current = head; 
        Node* next = NULL; 
        Node* prev = NULL; 
        int count = 0; 
        
        while (current != NULL && count < k) 
        { 
            next = current->next; 
            current->next = prev; 
            prev = current; 
            current = next; 
            count++; 
        } 
        
        if (next != NULL) 
            head->next = reverse(next, k, !toggle); 
        return prev; 
    }

    Node *tmp = head, *prev;
    int count = 0;
    while(tmp != NULL && count < k) {
        prev = tmp;
        tmp = tmp->next;
        count++;
    }
    
    if(tmp)
        prev->next = reverse(tmp, k, !toggle);

    return head;
}

int main() {
    head = NULL;
    insert(1, 1);
    insert(1, 2);
    insert(2, 3);
    insert(2, 4);
    insert(3, 5);
    insert(6, 6);
    insert(5, 7);
    insert(4, 8);
    insert(6, 9);
    insert(2, 10);
    display();
    
    head = reverse(head, 3, true);
    display();
}
