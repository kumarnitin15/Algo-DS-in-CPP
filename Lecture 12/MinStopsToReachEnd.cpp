#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int minStops(vector<int> stops, vector<int> fuel, int start, int end, int sf){
    priority_queue<int> pq;
    
    int n = stops.size();
    int currFuel = sf;
    int currPos = start;
    int count = 0;

    for(int i=0; i<n; i++){
        int dist = stops[i]-currPos;
        if(dist > currFuel){
            if(pq.empty())
                return -1;
            else {
                while(!pq.empty() && currFuel < dist){
                    currFuel += pq.top();
                    pq.pop();
                    count++;
                }
                if(currFuel < dist)
                    return -1;
                else {
                    currFuel -= dist;
                    pq.push(fuel[i]);
                    currPos = stops[i];
                }
            }
        }
        else {
            currFuel -= dist;
            pq.push(fuel[i]);
            currPos = stops[i];
        }
    }
    int dist = end - currPos;
    if(dist > currFuel){
        if(pq.empty())
            return -1;
        else {
            while(!pq.empty() && currFuel < dist){
                currFuel += pq.top();
                pq.pop();
                count++;
            }
            if(currFuel < dist)
                return -1;
        }
    }
    return count;
}

int main() {
    int start, end;

    cin >> start >> end;

    int sf; // start fuel
    cin >> sf;
    
    int n; // number of stops
    cin >> n;
    
    vector<int> stops(n); // positions of gas stations
    vector<int> fuel(n);  // fuel at each station

    for(int i=0; i<n; i++)
        cin >> stops[i] >> fuel[i];

    cout << "Minimum number of stops = " << minStops(stops, fuel, start, end, sf) << endl;
}