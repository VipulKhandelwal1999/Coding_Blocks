/*
Take the following as input.

A number (N1)
A number (N2)
Write a function which returns the LCM of N1 and N2. Print the value returned.

Input Format
Constraints
0 < N1 < 1000000000 0 < N2 < 1000000000

Output Format
Sample Input
4
6
Sample Output
12
Explanation
The smallest number that is divisible by both N1 and N2 is called the LCM of N1 and N2.

Logic:-
To find the LCM of two numbers, it is obvious that the LCM will be greater than or equal to the samller number in the two given numbers.

Algorithm

Take input of both the numbers say, N1 and N2.
Declare a variable with value with the smallest of the two numbers.
put a Infinite loop
Inside loop check if the variable can divide both the numbers,
If yes, break.
Otherwise increment the variable and continue.
Print the LCM obtained.
*/

#include<iostream>
int main() {
    int num1,num2;
    cin >> num1>>num2;

    if(num1>num2){
        int temp = num2;
        num2=num1;
        num1=temp;
    }

    int lcm=num2;
    while(lcm>0){
        if(lcm%num2==0 && lcm%num1==0){
            break;
        }
        lcm++;
    }
    cout << lcm << std::endl;
    return 0;
}
