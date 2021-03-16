/*
Given a head to Linked List L, write a function to reverse the list taking k elements at a time. Assume k is a factor of the size of List.

You need not have to create a new list. Just reverse the old one using head.

Input Format
The first line contains 2 space separated integers N and K

The next line contains N space separated integral elements of the list.

Constraints
0 <= N <= 10^6 0 <= K <= 10^6

Output Format
Display the linkedlist after reversing every k elements

Sample Input
9 3
9 4 1 7 8 3 2 6 5
Sample Output
1 4 9 3 8 7 5 6 2
Explanation
N = 9 & K = 3

Original LL is : 9 -> 4 -> 1 -> 7 -> 8 -> 3 -> 2 -> 6 -> 5

After k Reverse : 1 -> 4 -> 9 -> 3 -> 8 -> 7 -> 5 -> 6 -> 2

SOLUTION:-
The need of the question is to reverse every k nodes (where k is an input to the function) and k is a factor of size of List.

Example:

Inputs: 1->2->3->4->5->6->7->8->NULL and k = 3

Output: 3->2->1->6->5->4->8->7->NULL.

Algorithm :

Reverse the first sub-list of size k.

1.1 While reversing keep track of the next node and previous node.

1.2 Let the pointer to the next node be next and pointer to the previous node be prev.

head->next = reverse(next, k) // Recursively call for rest of the list and link the two sub-lists 

return prev  //prev becomes the new head of the list (see the diagrams of iterative method of this post) 

*/
Node reverse(Node head, int k)
    { 

       Node current = head; 
       Node next = null; 
       Node prev = null; 

       int count = 0; 

       /* Reverse first k nodes of linked list */
       while (count < k && current != null)  
       { 
           next = current.next; 
           current.next = prev; 
           prev = current; 
           current = next; 
           count++; 
       } 

       /* next is now a pointer to (k+1)th node  
          Recursively call for the list starting from current. 
          And make rest of the list as next of first node */
       if (next != null)  
          head.next = reverse(next, k); 

       // prev is now head of input list 
       return prev; 
}