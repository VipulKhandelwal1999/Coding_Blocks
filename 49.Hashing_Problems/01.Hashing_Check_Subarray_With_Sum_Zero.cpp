/*
Array contains a subarray whose sum is 0 or not
Approach:-
Make prefix sum and check whether any sum is repeating or not
So to check that use hashmap to store sum and if freq of any sum > 1
then just return true or we can return the starting index and ending index
*/

#include<iostream>
#include<unordered_set>
using namespace std;

bool checkSum(int arr[], int n){
    unordered_set<int> s;
    int pre = 0;
    for(int i=0; i<n; i++){
        pre += arr[i];
        //check if the sum was already present in the set
        if(pre == 0 or s.find(pre)!=s.end()){
            return true;
        }
        s.insert(pre);
    }
    return false;
}

int main() {

    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    if(checkSum(arr, n)){
        cout << "Yes";
    }
    else{
        cout << "No";
    }

    return 0;
}
