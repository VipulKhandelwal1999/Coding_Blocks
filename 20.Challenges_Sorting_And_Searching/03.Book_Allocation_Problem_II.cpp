/*
You are given number of pages in n different books and m students. The books are arranged in ascending order of number of pages. Every student is assigned to read some consecutive books. The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum.

Input Format
First line contains integer t as number of test cases. Next t lines contains two lines. For each test case, 1st line contains two integers n and m which represents the number of books and students and 2nd line contains n space separated integers which represents the number of pages of n books in ascending order.

Constraints
1 < t < 50
1< n < 100
1< m <= 50
1 <= Ai <= 1000

Output Format
Print the maximum number of pages that can be assigned to students.

Sample Input
1
4 2
12 34 67 90
Sample Output
113
Explanation
1st students : 12 , 34, 67 (total = 113)
2nd students : 90 (total = 90)
Print max(113, 90)

Logic:-
The idea is to use Binary Search. We fix a value for the number of pages as mid of current minimum and maximum. We initialize minimum and maximum as 0 and sum-of-all-pages respectively. If a current mid can be a solution, then we search on the lower half, else we search in higher half.

Now the question arises, how to check if a mid value is feasible or not? Basically, we need to check if we can assign pages to all students in a way that the maximum number doesn’t exceed current value. To do this, we sequentially assign pages to every student while the current number of assigned pages doesn’t exceed the value. In this process, if the number of students becomes more than m, then the solution is not feasible. Else feasible.
*/

public static long min(long[] arr, long n, long k) {
        long lo = arr[arr.length - 1];
        long totalpages = 0;
        long hi = 0;
        for (int i = 0; i < n; i++) {
            totalpages += arr[i];
        }
        hi = total_pages;
        long ans = 0;
        while (lo <= hi) {
            long mid = (lo + hi) / 2;
            boolean isvalid = isValid(arr, k, mid);
            if (isvalid) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
    private static boolean isValid(long[] arr, long k, long mid) {
        long sum = 0;
        int noOfstudents = 1;
        for (int i = 0; i < arr.length; i++) {
            sum += arr[i];
            if (sum > mid) {
                noOfstudents++;
                sum = arr[i];
                if (noOfstudents > k) {
                    return false;
                }
            }
        }
        return true;
    }
