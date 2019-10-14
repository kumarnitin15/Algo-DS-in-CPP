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

void removeLoop(Node* loop_node) 
{ 
   Node* ptr1 = loop_node; 
   Node* ptr2 = loop_node; 
  
    // Count the number of nodes in loop 
    unsigned int k = 1, i; 
    while (ptr1->next != ptr2) { 
        ptr1 = ptr1->next; 
        k++; 
    } 
  
    // Fix one pointer to head 
    ptr1 = head; 
  
    // And the other pointer to k nodes after head 
    ptr2 = head; 
    for (i = 0; i < k; i++) 
        ptr2 = ptr2->next; 
  
    /*  Move both pointers at the same pace, 
      they will meet at loop starting node */
    while (ptr2 != ptr1) { 
        ptr1 = ptr1->next; 
        ptr2 = ptr2->next; 
    } 
  
    // Get pointer to the last node 
    while (ptr2->next != ptr1) 
        ptr2 = ptr2->next; 
  
    /* Set the next node of the loop ending node 
      to fix the loop */
    ptr2->next = NULL; 
}

void detectAndRemoveloop() 
{ 
    Node *slow_p = head, *fast_p = head; 
  
    while (slow_p && fast_p && fast_p->next) { 
        slow_p = slow_p->next; 
        fast_p = fast_p->next->next; 
        if (slow_p == fast_p) { 
            cout << "Found Loop" << endl;
            removeLoop(slow_p);
            cout << "Loop removed" << endl;
            display(); 
            return; 
        } 
    } 
    cout << "Loop not found" << endl; 
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
    
    // Adding a loop in the list
    head->next->next->next->next->next->next = head->next->next;
    
    detectAndRemoveloop();
}
