#include <bits/stdc++.h> 
using namespace std; 

struct Queue { 
	stack<int> s; 

	void enQueue(int x) 
	{ 
		s.push(x); 
	} 

	int deQueue() 
	{ 
		if (s.empty()) { 
			cout << "Q is empty"; 
			exit(0); 
		} 
		int x = s.top(); 
		s.pop();  
		if (s.empty()) 
			return x; 
		int item = deQueue(); 
		s.push(x); 
		return item; 
	} 
}; 

int main() 
{ 
	Queue q; 
	q.enQueue(1); 
	q.enQueue(2); 
	q.enQueue(3); 

	cout << q.deQueue() << '\n'; 
	cout << q.deQueue() << '\n'; 
	cout << q.deQueue() << '\n'; 

	return 0; 
} 
