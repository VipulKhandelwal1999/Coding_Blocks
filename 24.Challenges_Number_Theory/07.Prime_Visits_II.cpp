/*
PMO gives two random numbers a & b to the Prime Minister. PM Modi wants to visit all countries between a and b (inclusive) , However due to shortage of time he can't visit each and every country , So PM Modi decides to visit only those countries,for which country number has two divisors. So your task is to find number of countries Mr. Modi will visit.



Input Format
The first line contains N , no of test cases. The next N lines contain two integers a and b denoting the range of country numbers.

Constraints
a<=1000000 & b<=1000000.
N<=1000

Output Format
Output contains N lines each containing an answer for the test case.

Sample Input
2
1 10
11 20
Sample Output
4
4
Explanation
PM Modi chooses countries with numbers 2,3,5 and 7 for the first testcase.
For the second testcase , he chooses countries with numbers 11,13,17 and 19.

Logic:-
You have to generate all primes number between a and b.
*/

#include <iostream>
using namespace std;
bool isPrime(int num){
    if(num<=0) return false;
    if(num==1) return false;
    if(num==2) return true;
    if((num&1)==0) return false;

    bool isPrime=true;
    for (int i = 3; i*i <=num ; i+=2) {
        if(num%i==0){
            isPrime=false;
            break;
        }
    }
    return isPrime;
}
int main() {
    int t;
    cin >> t;

    while(t--){
        int a,b;
        cin >> a>>b;

        int primes[b+1];
        primes[0]=0;
        primes[1]=0;

        for (int i = 2; i <= b; i++){
            if((i&1)==0||i<a){
                primes[i]=0;
            }else{
                primes[i]=1;
            }
        }
        if(2>=a){
            primes[2]=1;
        }
        for (int i = 3; i <=b; i+=2) {

            int j=2;
            while(i*j<=b){
                primes[i*j]=0;
                j++;
            }
        }

        int count=0;
        for (int i = 0; i <=b; i++) {
            if(primes[i]){
                count++;
            }
        }

        cout << count <<endl;
    }
}
