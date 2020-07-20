#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

bool compare(int a,int b){
    cout<<"Comparing "<<a<<" and "<<b<<endl;
    return a<b;
}

int main() {

    int a[1000];
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //Function ko as a parameters to sort function,
    //Function Sort , Compare is not called here - Compare is called internally
    sort(a,a+n,compare);

    for(int i=0;i<n;i++){
       cout<<a[i]<<",";
    }



    return 0;
}
