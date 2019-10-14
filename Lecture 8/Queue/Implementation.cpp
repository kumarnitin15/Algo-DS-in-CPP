#include <bits/stdc++.h> 
using namespace std; 

#define MAX 1000 

class Queue { 
	int front, rear; 

public: 
	int a[MAX]; // Maximum size of Queue 

	Queue() { front = -1; rear = 0; } 
	bool enqueue(int x); 
	int deque(); 
	int peek(); 
	bool isEmpty(); 
}; 

bool Queue::enqueue(int x) 
{ 
	if (rear > (MAX - 1)) { 
		cout << "Queue Overflow"; 
		return false; 
	} 
	else { 
        if(front == -1){
            a[0] = x;
            front++; rear++;
        }
        else 
            a[rear++] = x; 
        cout << x << " Pushed into queue\n"; 
		return true; 
	} 
} 

int Queue::deque() 
{ 
	if (front >= rear) { 
		cout << "Queue Underflow"; 
		return 0; 
	} 
	else { 
		int x = a[front++]; 
		return x; 
	} 
} 
int Queue::peek() 
{ 
	if (front > rear) { 
		cout << "Queue is Empty"; 
		return 0; 
	} 
	else { 
		int x = a[front]; 
		return x; 
	} 
} 

bool Queue::isEmpty() 
{ 
	return (front <= rear); 
} 

int main() 
{ 
	class Queue q; 
	q.enqueue(10); 
	q.enqueue(20); 
	q.enqueue(30); 
	cout << q.deque() << " Popped from queue\n"; 

	return 0; 
} 