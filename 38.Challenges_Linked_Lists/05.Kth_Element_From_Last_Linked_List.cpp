/*
Given a linked list with n nodes. Find the kth element from last without computing the length of the linked list.

Input Format
First line contains space separated integers representing the node values of the linked list. The list ends when the input comes as '-1'. The next line contains a single integer k.

Constraints
n < 10^5

Output Format
Output a single line containing the node value at the kth element from last.

Sample Input
1 2 3 4 5 6 -1
3
Sample Output
4
Explanation
The linked list is 1 2 3 4 5 6. -1 is not included in the list. So the third element from the last is 4
*/
/*
SOLUTION:-
There are two approaches to solve this question:

Method 1
1) Calculate the length of Linked List. Let the length be len.
2) Print the (len – n + 1)th node from the begining of the Linked List.

Method 2 (Use two pointers)
1) Maintain two pointers – reference pointer and main pointer.
2) Initialize both reference and main pointers to head.
3) First move reference pointer to n nodes from head.
4) Now move both pointers one by one until reference pointer reaches end.
5) Now main pointer will point to nth node from the end.
6) Return main pointer.
*/

public int KthElementFromLast(LinkedList ll, int k) {
            Node slow = ll.head;
            Node kp = ll.head;
            int count = k;
            while (count > 0) {
                kp = kp.next;
                count--;
            }
            while (kp.next != null) {
                kp = kp.next;
                slow = slow.next;
            }
            // slow=slow.next;
            return slow.data;
        }
