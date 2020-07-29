//-Space Optimised Sieve using bitset
//- Checking if a large no is Prime or Not ~ 10^12
//Sieve Limitation - 10^7

#include<iostream>
#include<bitset>
#include<vector>
using namespace std;

const int n = 10000000;
bitset<10000005> b;
vector<int> primes;

void sieve() {

    //set all bits
    b.set(); //1,1,1,1,1,...
    b[0] = b[1] = 0;
    for(long long int i=2; i<=n; i++){
        if(b[i]){
            primes.push_back(i);
            for(long long int j = i*i; j<=n; j++){
                b[j] = 0;
            }
        }
    }


}

bool isPrime(long long No){
    if(No <= n){
        return b[No] == 1 ? true : false;
    }
    for(long long i=0; primes[i]*(long long)primes[i]<= No; i++){
        if(No%primes[i] == 0){
            return false;
        }
    }
    return true;
}

int main(){

    sieve();
    // 2147483647 = 10 digit prime no.
    long long n = 3;
    if(isPrime(n))
        cout << "yes it is" << endl;
    else
        cout << "No it is not" << endl;

    return 0;
}
