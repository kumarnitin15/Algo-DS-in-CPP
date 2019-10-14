#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *insert(Node *head, int pos, int data){
    Node *t = new Node;
    t->data = data;
    t->next = NULL;
    
    if(pos == 1){
        t->next = head;
        head = t;
        return head;
    }
    
    Node *tmp = head; int cnt = 1;
    while(tmp && cnt < pos-1){
        tmp = tmp->next;
        cnt++;
    }
   
    if(!tmp){
        cout << "Invalid position" << endl;
        return head;
    }
   
    t->next = tmp->next;
    tmp->next = t;

    return head;
}

void display(Node *head){
    Node *tmp = head;
    while(tmp) {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int getCount(Node* head) 
{ 
    Node* current = head; 
    int count = 0; 
    while (current != NULL) { 
        count++;  
        current = current->next; 
    } 
    return count; 
} 

/* function to get the intersection point of two linked  
lists head1 and head2 where head1 has d more nodes than  
head2 */
int _getIntesectionNode(int d, Node* head1, Node* head2) 
{ 
    // Stand at the starting of the bigger list 
    Node* current1 = head1; 
    Node* current2 = head2; 
  
    // Move the pointer forward 
    for (int i = 0; i < d; i++) { 
        if (current1 == NULL) { 
            return -1; 
        } 
        current1 = current1->next; 
    } 
  
    // Move both pointers of both list till they 
    // intersect with each other 
    while (current1 != NULL && current2 != NULL) { 
        if (current1 == current2) 
            return current1->data; 
  
        // Move both the pointers forward 
        current1 = current1->next; 
        current2 = current2->next; 
    } 
  
    return -1; 
} 

/* function to get the intersection point of two linked  
lists head1 and head2 */
int getIntesectionNode(Node* head1, Node* head2) 
{ 
  
    // Count the number of nodes in 
    // both the linked list 
    int c1 = getCount(head1); 
    int c2 = getCount(head2); 
    int d; 
  
    // If first is greater 
    if (c1 > c2) { 
        d = c1 - c2; 
        return _getIntesectionNode(d, head1, head2); 
    } 
    else { 
        d = c2 - c1; 
        return _getIntesectionNode(d, head2, head1); 
    } 
}

int main() {
    Node *h1 = NULL, *h2 = NULL;
    
    // Creating list 1
    h1 = insert(h1, 1, 1);
    h1 = insert(h1, 1, 2);
    h1 = insert(h1, 2, 3);
    h1 = insert(h1, 2, 4);
    h1 = insert(h1, 3, 5);
    h1 = insert(h1, 6, 6);
    h1 = insert(h1, 2, 13);
    h1 = insert(h1, 2, 14);

    // Creating list 2
    h2 = insert(h2, 1, 13);
    h2 = insert(h2, 2, 42);
    h2 = insert(h2, 3, 5);
    h2 = insert(h2, 4, 60);

    // Creating Intersection
    Node *t1 = h1->next->next->next->next->next;
    Node *t2 = h2->next->next->next;
    t2->next = t1;
    display(h1);
    display(h2);
    
    cout << getIntesectionNode(h1, h2) << endl;
}