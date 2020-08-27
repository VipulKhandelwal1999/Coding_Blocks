/*
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,…,xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?

Input Format
First line contains N and C, separated by a single space, representing the total number of stalls and number of cows respectively. The next line contains N integers containing the indexes of stalls.

Constraints
2 <= N <= 100,000
0 <= xi <= 1,000,000,000
2 <= C <= N

Output Format
Print one integer: the largest minimum distance.

Sample Input
5 3
1 2 8 4 9
Sample Output
3
Explanation
Problem Credits - (Spoj)[http://www.spoj.com/problems/AGGRCOW/]

Logic:-
For this problem, fix one cow at the first position and then move ahead.

So I have created a minimum Distance function which basically calculates a mid point and treats that as the minimum distance to place a cow. If we have a position greater than or equal to this distance, we fix the cow at that position.

Now the isValid Function takes as input the the minimum distance (or the mid point), number of cows, the array of stall positions and size of the array


*/



long minDist(long stalls[],int n,int k){

int s = stalls[0];
int e = stalls[n-1];

int ans = 0;
int mid = 0;
while(s+1<e){      //here if you take s<e, it will become an infinite loop once we reach the required answer.
    mid = (s+e)/2;

    if(isValid(stalls,n,k,mid)==1){
        s = mid;
    }
    else{
        e = mid;
    }
}
return s;
}

int isValid(long stalls[],int n,int s,int current_ans){

int cow = 1;
int currently_alloted = stalls[0];

for(int i=1;i<n;i++){

    if(stalls[i]-currently_alloted >= current_ans){
        cow++;
        if(cow==s){
            return 1;
        }
        currently_alloted = stalls[i];

    }
}
return 0;
}
