// Implementation of a max heap 

#include <iostream>
#include <vector>
using namespace std;

class Heap {
    vector<int> v;

    public:

        void push(int data){
            v.push_back(data);
            int index = v.size()-1;
            
            if(index == 0)
                return;

            int parent = (index-1)/2;

            while(index > 0 && v[parent] < v[index]){
                int t = v[parent];
                v[parent] = v[index];
                v[index] = t;
                index = parent;
                parent = (index-1)/2;
            }

        }

        void heapify(int index){
            int n = v.size();

            while(index < n){
                int left = 2*index + 1;
                int right = 2*index + 2;
                int maximum = v[index];
                int ind = index;

                if(left < n && v[index] < v[left]){
                    maximum = v[left];
                    ind = left;
                }

                if(right < n && maximum < v[right]){
                    maximum = v[right];
                    ind = right;
                }

                int t = v[index];
                v[index] = v[ind];
                v[ind] = t;

                if(index != ind)
                    index = ind;
                else
                    break;
            }
        }

        void buildHeap(vector<int> arr){
            
            int n = arr.size();

            for(int i=0; i<n; i++)
                v.push_back(arr[i]);
            
            int index = (n/2)-1;
            
            for(int i=index; i>=0; i--)
                heapify(i);
        }

        void pop(){
            int n = v.size();

            if(n == 0)
                return;

            v[0] = v[n-1];
            v.pop_back();

            heapify(0);
        }

        int getMin(){
            return v[0];
        }

        bool empty(){
            return (v.size() == 0);
        }
};

void printHeap(Heap h){
    while(!h.empty()){
        cout << h.getMin() << " ";
        h.pop();
    }
}

int main() {
    
    Heap h;

    vector<int> arr{1,2,3,4,5,6,7,8,9,10};

    h.buildHeap(arr);

    h.push(11);
    h.push(14);
    h.push(13);
    h.push(12);

    printHeap(h);
}