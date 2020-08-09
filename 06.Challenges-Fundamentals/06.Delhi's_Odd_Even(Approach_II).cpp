/*
Due to an immense rise in Pollution, Kejriwal is back with the Odd and Even Rule in Delhi. The scheme is as follows, each car will be allowed to run on Sunday if the sum of digits which are even is divisible by 4 or sum of digits which are odd in that number is divisible by 3. However to check every car for the above criteria can't be done by the Delhi Police. You need to help Delhi Police by finding out if a car numbered N will be allowed to run on Sunday?

Input Format
The first line contains N , then N integers follow each denoting the number of the car.

Constraints
N<=1000 Car No >=0 && Car No <=1000000000

Output Format
N lines each denoting "Yes" or "No" depending upon whether that car will be allowed on Sunday or Not !

Sample Input
2
12345
12134
Sample Output
Yes
No
Explanation
1 + 3 + 5 = 9 which is divisible by 3
1 + 1 + 3 = 5 which is NOT divisible by 3 and 2+4 = 6 which is not divisble by 4.

Logic:-
The Question in Simple language is that:

You have given a number and in that number, the digits which are even should have sum divisible by 4 or the sum of digits which are odd should be divisible by the 3, Only then you can say yes otherwise you will say no.

Algorithm

Take input of the Number.
Declare two variables to store the sum of even numbers and odd numbers.
Extract digit one by one ( by % 10).
Check if the number is even or odd.
If even add the number in the variable storing even sum.
Othewise add it in the variable storing odd sum.
After the loop, Check if the even sum is divisible by 4.
If True, print Yes.
otherwise print No.
Check if the odd sum is divisible by 3.
If True, print Yes.
otherwise print No.
*/
void oddEven(int n){

        int oddSum = 0;
        int evenSum = 0;

        while(n != 0){

            int rem = n % 10;
            if(rem % 2 == 0){
                evenSum += rem;
            }else{
                oddSum += rem;
            }

            n = n/ 10;
        }

        if(evenSum % 4 == 0 || oddSum % 3 == 0){
            cout << "Yes" << endl;
        }else{
             cout << "NO" << endlo
        }
    }
