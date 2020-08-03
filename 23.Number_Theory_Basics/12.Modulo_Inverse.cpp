#include <iostream>
using namespace std;

long long fast_power(long long base, long long power, long long MOD) {
    long long result = 1;
    while(power > 0) {

        if(power % 2 == 1) { // Can also use (power & 1) to make code even faster
            result = (result*base) % MOD;
        }
        base = (base * base) % MOD;
        power = power / 2; // Can also use power >>= 1; to make code even faster
    }
    return result;
}

long long modulo_multiplicative_inverse(long long A, long long M) {
    // Assumes that M is a prime number
    // Returns multiplicative modulo inverse of A under M
    return fast_power(A, M-2, M);
}

int main() {
    cout <<  modulo_multiplicative_inverse(5, 11) << endl;
    // Output: 9 (Because 5*9 % 11 => 45 % 11 = 1)
    cout <<  modulo_multiplicative_inverse(3, 8) << endl;
    // Output: 3 (Because 3*3 % 8 => 9 % 8 = 1)
    cout <<  modulo_multiplicative_inverse(3, 1000000007) << endl;
    // Output: 739130440 (Because 739130440*23 = 17000000120 and 17000000120 % 1000000007 is 1)
    return 0;
}
