/*
Take as input N, the size of array. Take N more inputs and store that in an array. Take as input M, the size of second array and take M more inputs and store that in second array. Write a function that returns the sum of two arrays. Print the value returned.

Input Format
Constraints
Length of Array should be between 1 and 1000.

Output Format
Sample Input
4
1 0 2 9
5
3 4 5 6 7
Sample Output
3, 5, 5, 9, 6, END
Explanation
Sum of [1, 0, 2, 9] and [3, 4, 5, 6, 7] is [3, 5, 5, 9, 6] and the first digit represents carry over , if any (0 here ) .

Logic:-
For the given sample case , arr1=[1, 0, 2, 9] and arr2=[3, 4, 5, 6, 7] .Each element of both the arrays is a digit .Thus, both array forms two separate numbers and we need to calculate the sum of these two numbers.

Take an ans array (whose size is equal to the (max size of the two arrays +1 )) which will store the final number formed.

Start adding both the numbers digit by digit from the end i.e. 9+7=16 thus 6 is stored in the ans array at last index (as we are updating our array from last) and 1 is taken as carry.Thus, this process is repeated for every digit and at the end if carry is not 0 it is stored at the starting index of the ans array.First digit of the ans array represent carry over which is zero in this case. So ans is [3, 5, 5, 9, 6].

Algorithm:
1.Traverse both the arrays simultaneously from the end until we reach the 0th index of either of the array.
2.While traversing each element of array, add an element from both arrays and carry from the previous sum.
…………2.1 Store the unit digit of the sum(obtained by doing - sum%10) in the ans array.
…………2.2 forward carry(obtained by doing - sum/10) for the next index sum.
3.After the loop ends we are left with one of the arrays and the carry.
4.We will now repeat step 2 but now for one array which is left after the loop.
5.If carry !=0 then store the carry in the 0th index of ans array.
6.Print the ans array .
*/

void arraySum(int[] one, int[] two) {

        ArrayList ans = new ArrayList<>();

        int i = one.length - 1;
        int j = two.length - 1;

        int carry = 0;
        while (i >= 0 || j >= 0) {

            int sum = carry;

            if (i >= 0) {
                sum += one[i];
            }

            if (j >= 0) {
                sum += two[j];
            }

            int rem = sum % 10;
            ans.add(0, rem);
            carry = sum / 10;

            i--;
            j--;
        }

        if (carry != 0) {
            ans.add(0, carry);
        }

        for (i = 0; i < ans.size(); i++) {
            System.out.print(ans.get(i) + ", ");
        }
        System.out.println("END");
    }

