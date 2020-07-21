#include<bits/stdc++.h>
using namespace std;

//Templates + Iterators + Comparators

template<class ForwardIterator, class T, class Compare>
ForwardIterator search(ForwardIterator start,ForwardIterator end, T key, Compare cmp){
    while(start != end){
        if(cmp(*start,key)){
            return start;
        }
        start++;
    }
    return end;
}

class BookCompare(){

}
