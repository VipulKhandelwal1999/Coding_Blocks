#include<bits/stdc++.h>
using namespace std;

//Approach-I
void allOccurences(int *a, int i, int n, int key){

    // Base Case
    if(i == n)
        return;
    //Recursive Case
    if(a[i] == key)
        cout << i << " ";

    allOccurences(a, i+1, n, key);
}

int storeOccurence(int *a, int i, int n, int key, int *out, int j){

    // Base Case
    if(i == n)
        return j;

    //Recursive Case
    if(a[i] == key){
        out[j] = i;
        return storeOccurence(a, i+1, n, key, out, j+1);
    }
    // j remains unchanged
    return storeOccurence(a, i+1, n, key, out, j);
}


int main(){
    int arr[] = {1,3, 2,4,5,2};
    allOccurences(arr, 0, 5, 2);
    int output[100];
    int count = storeOccurence(arr, 0, 6, 2, output, 0);
    cout << endl;
    for(int i=0; i<count; i++){
        cout << output[i] << " ";
    }
    return 0;
}
