#include <bits/stdc++.h> 
using namespace std; 

struct Node { 
	int data; 
	struct Node* link; 
}; 
struct Node* front, *rear; 

void enqueue(int data) 
{ 
	struct Node* temp; 
	temp = new Node(); 

	if (!temp) { 
		cout << "\nHeap Overflow"; 
		exit(1); 
	} 

    temp->data = data;
    temp->link = NULL;

    if(!rear)
        front = rear = temp;
    
    else {
        rear->link = temp;
        rear = temp;
    }
} 

bool isEmpty() 
{ 
	return front == NULL; 
} 

int peek() 
{ 
	if (!isEmpty()) 
		return front->data; 
	else
		exit(1); 
}  

void dequeue() 
{ 
	struct Node* temp; 

	if (!front) { 
		cout << "\nQueue Underflow" << endl; 
		exit(1); 
	} 
	else {  
		temp = front; 
		front = front->link; 
        temp->link = NULL; 
        free(temp); 
	} 
} 

void display() 
{ 
	struct Node* temp; 
	if (front == NULL) { 
		cout << "\nQueue Underflow"; 
		exit(1); 
	} 
	else { 
		temp = front; 
		while (temp != NULL) { 
			cout << temp->data << " "; 
			temp = temp->link; 
		} 
	} 
} 
 
int main() 
{ 
	front = rear = NULL;
    
    enqueue(11); 
	enqueue(22); 
	enqueue(33); 
	enqueue(44); 

	display(); 

	cout << "\nFront element is " << peek() << endl; 
	
    dequeue(); 
	dequeue(); 

	display(); 

	cout << "\nFront element is " << peek() << endl; 
	return 0; 
} 
