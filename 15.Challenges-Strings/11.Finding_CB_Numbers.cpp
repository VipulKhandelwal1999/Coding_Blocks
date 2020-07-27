/*
Deepak and Gautam are having a discussion on a new type of number that they call Coding Blocks Number or CB Number. They use following criteria to define a CB Number.

0 and 1 are not a CB number.
2,3,5,7,11,13,17,19,23,29 are CB numbers.
Any number not divisible by the numbers in point 2( Given above) are also CB numbers.
Deepak said he loved CB numbers.Hearing it, Gautam throws a challenge to him.

Gautam will give Deepak a string of digits. Deepak's task is to find the number of CB numbers in the string.

CB number once detected should not be sub-string or super-string of any other CB number.
Ex- In 4991, both 499 and 991 are CB numbers but you can choose either 499 or 991, not both.

Further, the CB number formed can only be a sub-string of the string.
Ex - In 481, you can not take 41 as CB number because 41 is not a sub-string of 481.

As there can be multiple solutions, Gautam asks Deepak to find the maximum number of CB numbers that can be formed from the given string.

Deepak has to take class of Launchpad students. Help him by solving Gautam's challenge.

Input Format
First line contain size of the string.

Next line is A string of digits.

Constraints
1 <= Length of strings of digits <= 17

Output Format
Maximum number of CB numbers that can be formed.

Sample Input
5
81615
Sample Output
2
Explanation
61 and 5 are two CB numbers.
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll MakeNumber(char *num,ll digit){
    ll ans = 0;
    for(ll i=0; i<digit; i++){
        ans= (ans*10) + (num[i]-'0');
    }
    return ans;
}

bool IsCBNumber(ll p){
     if(p==1 || p==0)
    return 0;

    ll arr[10]={2,3,5,7,11,13,17,19,23,29};
    for(ll y=0; y<10; y++)
    {
        if(p == arr[y])
			return 1;
        if(p % arr[y] == 0)
        	return 0;
    }
    return 1;
}

ll CBNumber(char* num,ll n){
    ll Max = INT_MIN;
    for(int i=0; i<n; i++){
        for(ll j=1; j<=n-i; j++){
            ll number = MakeNumber(num+i,j);
            if(IsCBNumber(number)){
                ll ans = CBNumber(num+j+i,n-j-i)+1;
                if(Max<ans){
                        Max=ans;
                }
            }
        }
    }
    if(Max!=INT_MIN) return Max;
    return 0;
}

int main(){

	ll n;
	cin >> n;
	char num[30];
	cin >> num;
	cout << CBNumber(num,n);

	return 0;
}
