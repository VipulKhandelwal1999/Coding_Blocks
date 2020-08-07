#include<bits/stdc++.h>
using namespace std;

//Median in a Running Stream Of Integers
int main() {

    priority_queue<int> leftheap; //maxHeap
    priority_queue<int, vector<int>, greater<int>> rightheap; //minHeap

    int d;
    cin >> d;
    leftheap.push(d);

    float med = d;
    cout << "Median " << med << " ";

    cin >> d;
    cout << endl;
    //input all elements
    while(d!=-1){
        //logic
        if(leftheap.size() > rightheap.size()){
            if(d<med){
                rightheap.push(leftheap.top());
                leftheap.pop();
                leftheap.push(d);
            }
            else{
                rightheap.push(d);
            }
            med = (leftheap.top() + rightheap.top())/2;
        }
        else if(leftheap.size() == rightheap.size()){
            if(d<med){
                leftheap.push(d);
                med = leftheap.top();
            }
            else{
                rightheap.push(d);
                med = rightheap.top();
            }
        }
        else{
            if(d>med){
                leftheap.push(rightheap.top());
                rightheap.pop();
                rightheap.push(d);
            }
            else{
                leftheap.push(d);
            }
            med = (leftheap.top() + rightheap.top())/2;
        }
        cout << "Med " << med << endl;
        cin >> d;
    }

    return 0;
}
