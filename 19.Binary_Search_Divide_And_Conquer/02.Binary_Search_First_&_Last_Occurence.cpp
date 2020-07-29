#include <iostream>
using namespace std;
int first_occurence(int a[],int n,int key)
{
    int S = 0;
    int E = n-1;
    int ans = -1;
    while(S<=E)
    {
        int mid = (E+S)/2;
        if(a[mid] == key)
        {
            ans = mid;
            E = mid-1;
        }
        else if(a[mid] > key)
        {
            E = mid-1;
        }
        else
        {
            S = mid+1;
        }
    }
    return ans;
}

int last_occurence(int a[],int n,int key)
{
    int S = 0;
    int E = n-1;
    int ans = -1;
    while(S<=E)
    {
        int mid = (E+S)/2;
        if(a[mid] == key)
        {
            ans = mid;
            S = mid+1;
        }
        else if(a[mid] > key)
        {
            E = mid-1;
        }
        else
        {
            S = mid+1;
        }
    }
    return ans;
}
int main()
{
    //int arr[] = {1,2,5,8,8,8,8,8,10,12,15,20};
    //int n = sizeof(arr)/sizeof(int);
    int n;
    cin>>n;
    int arr[1000000];

    for(int i=0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    int testcases;
    cin >> testcases;
    while(testcases>0)
    {
         cin >> key;
         cout << first_occurence(arr,n,key) << " ";
         cout << last_occurence(arr,n,key) << endl;
         testcases--;
    }
    return 0;
}
