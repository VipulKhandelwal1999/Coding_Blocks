/*
Take N as input, Calculate it's reverse also Print the reverse.

Input Format
Constraints
0 <= N <= 1000000000

Output Format
Sample Input
123456789
Sample Output
987654321
Explanation
You've to calculate the reverse in a number, not just print the reverse.

Logic:-
For the Given input,

123456789

The corresponding ans is 987654321,To achieve this answer we must know how to access the last digit of a number viz, if we perform modulus 10 with any number we got the last digit of that number.

for e.g, 123 % 10 = 3, and now to modify the number we need to remove the 3 from the digit as it is accounted so we have perfrom divide by 10 action to reduce the length by 1.

for e.g., 123 / 10 = 12. we must perform both the operations till we got Zero as the number, and most importantly to build the ans we can construct it by multipying it by 10 and then add to the answer.

for e.g., ans = 12, if u want to add 3 so u need to multiply 12 by 10 and then add the num, so it become 12*10 + 3 = 123.
*/

int reverse(int n){
     int ans = 0;
        while(n != 0){
          int digit = n % 10;
          ans = ans *10 + digit;
          n /= 10;
        }
       return ans;
}
