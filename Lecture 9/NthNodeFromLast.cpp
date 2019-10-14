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

void printNthFromLast(int n) 
{ 
  Node *main_ptr = head; 
  Node *ref_ptr = head; 
  
  int count = 0; 
  if(head != NULL) 
  { 
     while( count < n ) 
     { 
        if(ref_ptr == NULL) 
        { 
           cout << n << " is greater than the no. of nodes in list" << endl;
           return; 
        } 
        ref_ptr = ref_ptr->next; 
        count++; 
     }
  
     while(ref_ptr != NULL) 
     { 
        main_ptr = main_ptr->next; 
        ref_ptr  = ref_ptr->next; 
     } 
     cout << "Node no. " << n << " from the last is " << main_ptr->data << endl; 
  } 
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
    display();
    
    printNthFromLast(4);
}
