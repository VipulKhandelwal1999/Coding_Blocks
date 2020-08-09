/*
Take the following as input.

A number (N1)
A number (N2)
Write a function which prints first N1 terms of the series 3n + 2 which are not multiples of N2.

Input Format
Constraints
0 < N1 < 100 0 < N2 < 100

Output Format
Sample Input
10
4
Sample Output
5
11
14
17
23
26
29
35
38
41
Explanation
The output will've N1 terms which are not divisible by N2.

Logic:-
For the input:
3
2
Then we need to print first 3 terms starting from n = 1 in the given series (3n + 2) which are not divisible by 2.
In that case nums starting from n = 1 are 5, 8, 11, 14, 17, 23… and so on. but we need to print only those numbers which are not divisible by 2, which are, 5, 11, 17.

The problem most of the students will face is
"how to print first N1 terms?"
"What should be the condition to end the loop?" as the N1 terms are not defined.
Ans is simple we will use a counter variable and initialize it with 0 and will increment it only when we got the number in the series which is not divisible by N2 till the counter is smaller than N1.
*/

void print(int n1,int n2){

     int n=1;int count=1;
    while(count <= n1){

        int ans=3*n+2;
        if(ans%n2!=0){
            System.out.println(ans);
            count++;

        }
        n++;
      }
}
