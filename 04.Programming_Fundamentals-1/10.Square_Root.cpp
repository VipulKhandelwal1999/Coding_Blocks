#include<iostream>
using namespace std;


int main() {

	// Give a Number N
	// Square root of the number without using any predefined function
	int N;
	int P;
	cin >> N >> P;


	float ans = 0;
	float inc = 1.0;

	for (int times = 0; times <= P; times++) {

		// Finalise the correct digit for the current place
		while (ans * ans <= N) {
			ans = ans + inc;
		}
		ans = ans - inc ;
		// Updates the increment for the next position
		inc = inc / 10;
	}

	cout << ans << endl;

    /*
    Inbuilt Functions to compute square root:-
    1. (For double)sqrt:- It returns the square root of a number to type double
    2. (For long long)sqrtl:- It returns the square root of a number to type long double with more precision.
    3. (For float)sqrtf
    Left mentioned things are what value they return and in all of the above sqrtl has most precision

    Usage:-
    1.
    double val1 = 300.0;

    cout << fixed << setprecision(12) << sqrt(val1) << endl;

    Output:
    17.320508075689

    2.
    long long int val1 = 1000000000000000000;
    long long int val2 = 999999999999999999;

    cout << fixed << setprecision(12) << sqrt(val1) << endl;
    cout << fixed << setprecision(12) << sqrt(val2) << endl;

    Output:
    1000000000.000000000000
    999999999.999999999476

    3.
    float val1 = 225.0;
    float val2 = 300.0;

    cout << fixed << setprecision(12) << sqrtf(val1) << endl;
    cout << fixed << setprecision(12) << sqrtf(val2) << endl;

    Output:
    15.000000000000
    17.320508956909

    */

	return 0;
}
