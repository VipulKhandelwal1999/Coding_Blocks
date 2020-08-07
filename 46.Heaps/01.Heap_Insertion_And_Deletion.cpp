/*
Priority Queue/Heap
Motivation_Problem:-Find max, min of n elements
Insertion - O(logn)
Pop - O(logn)
Get - O(1)

Properties of heap:-
1.Binary Tree
2.Complete Binary Tree :- All levels are completely filled except
last level but the filling must be from left to right order
3.Heap Order Property:-
Max Heap:- Every Parent > Children
Min Heap:- Every Parent < Children
We will store heap in array because if we choose binary tree then to insert element we have to do level order traversal which itself will take O(n) time
We will use array and start indexing from 1
if Array element is i then its children will be present as 2*i, 2*i+1 and parent will be at floor(i/2)
In array we can insert at last in O(1) time
*/

#include<iostream>
#include<vector>
using namespace std;

//If type = true then minHeap else maxHeap

class Heap {
    vector<int> v;
    bool minHeap;

    bool compare(int a, int b){
        if(minHeap){
            return a<b;
        }
        else{
            return a>b;
        }
    }

    void heapify(int idx) {
        int left = 2*idx;
        int right = left + 1;
        int min_idx = idx;
        int last = v.size() - 1;
        if(left <= last && compare(v[left],v[idx])){
            min_idx = left;
        }
        if(right<=last && compare(v[right], v[min_idx])){
            min_idx = right;
        }
        if(min_idx != idx){
            swap(v[idx], v[min_idx]);
            heapify(min_idx);
        }
    }

    public:
        Heap(int default_size=10, bool type=true){
            v.reserve(default_size);
            v.push_back(-1); //To block the 0th index
            minHeap = type;
        }

        void push(int d){
            v.push_back(d);
            int idx = v.size()-1;
            int parent = idx/2;

            //Keep pushing to the top till you reach a root node or stop midway because current element is always greater than parent

            while(idx > 1 and compare(v[idx], v[parent])){
                swap(v[idx], v[parent]);
                idx = parent;
                parent = parent/2;
            }
        }
        int top() {
            return v[1];
        }

        void pop(){
            int last = v.size() - 1;
            swap(v[1], v[last]);
            v.pop_back();
            heapify(1);
        }
        bool empty() {
            return v.size() == 1;
        }
};

int main() {

    Heap h;
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        int no;
        cin >> no;
        h.push(no);
    }

    //remove all the elements one by one
    while(!h.empty()){
        cout << h.top() << ", ";
        h.pop();
    }

    Heap h1(10, false);

    for(int i=0; i<n; i++){
        int no;
        cin >> no;
        h1.push(no);
    }

    //remove all the elements one by one
    while(!h1.empty()){
        cout << h1.top() << ", ";
        h1.pop();
    }


    return 0;
}
