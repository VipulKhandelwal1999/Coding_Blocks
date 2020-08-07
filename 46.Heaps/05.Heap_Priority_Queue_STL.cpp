//Priority:- We have to tell the priority that how we want the element
//Push:- O(logn)
//Pop:- O(logn)
//Underlying data structure:- Heap
//Root element:- top :- O(1)

#include<iostream>
#include<queue>
using namespace std;

int main() {

    priority_queue<int> pq; //max Heap by default
    int n;
    cin >> n;
    for(int i=1; i<n; i++){
        int no;
        cin >> no;
        pq.push(no); //O(logn)
    }
    //Remove the elements from the heap
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    priority_queue<int, vector<int>, greater<int>> pw; //To convert it into Min Heap
    int x;
    cin >> x;
    for(int i=1; i<n; i++){
        int no;
        cin >> no;
        pw.push(no); //O(logn)
    }
    //Remove the elements from the heap
    while(!pw.empty()){
        cout << pw.top() << " ";
        pw.pop();
    }
    return 0;
}
