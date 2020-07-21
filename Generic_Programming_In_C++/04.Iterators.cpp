#include<bits/stdc++.h>
using namespace std;
/*
int search(int arr[],int n,int key){

    for(int p=0;p<n;p++){
        if(arr[p]==key){
            return p;
        }
    }
    //return n if element not found
    return n;
}
*/

template<class ForwardIterator, class T>
ForwardIterator search(ForwardIterator start,ForwardIterator end, T key){
    while(start != end){
        if(*start == key){
            return start;
        }
        start++;
    }
    return end;
}

int main(){
    /*
    int arr[] = {1,3,5,7,10,12};
    int n = sizeof(arr)/sizeof(int);
    cout<<search(arr,n,10)<<endl;
    */
    list<int> l;

    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    auto it = search(l.begin(), l.end(), 2);
    if(it == l.end()){
        cout << "Element Not Found";
    }
    else
        cout << "Element Found: " << *it;

    return 0;
}
