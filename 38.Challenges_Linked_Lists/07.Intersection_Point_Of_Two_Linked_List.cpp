/*
Given two intersecting linked lists, write a function to find its point of intersection. If the lists do not intersect , return NULL.

Note : You are required to only write a single function. Do not modify / alter the remaining code.

This is a stub problem so you need not worry about taking input or displaying output. Only focus on the designated function.

Input Format
You are given a function which accepts head pointers of two linked lists.

Constraints
Your function should run in linear time.

Output Format
Return the intersection point node.

Sample Input
Consider these linked lists :
1 -> 2 -> 3  -> null
   ↗
4

(This is not the actual input that will be provided but rather a description of it)
Sample Output
The two linked lists 1->2->3->null and 4->2->3-> null intersect at node with data 2.
Return the node with data = 2.
Explanation
The two linked lists intersect at 2. Return their intersection point.
*/
/*
SOLUTION:-
The first method is ofcourse the brute force approach that we could iterate over one linked list , and for each element , check its presence in the other linked list. This will be a O(n^2) approach.
The second approach that comes to mind is that we could find the lengths of the two linked lists , traverse the longer linked list ahead a few steps by the difference of the two lists. This will work in O(max(m,n)) time where m and n are the lengths of the two linked lists.
A third and different approach is to find intersection point without finding the lengths of the lists. Actually we don't care about the "value" of difference, we just want to make sure two pointers reach the intersection node at the same time.

We can use two iterations to do that. In the first iteration, we will reset the pointer of one linkedlist to the head of another linkedlist after it reaches the tail node. In the second iteration, we will move two pointers until they points to the same node. Our operations in first iteration will help us counteract the difference. So if two linkedlist intersects, the meeting point in second iteration must be the intersection point. If the two linked lists have no intersection at all, then the meeting pointer in second iteration must be the tail node of both lists, which is null

My understanding:
ListA = A + intersection
ListB = B + intersection
with this solution, it's like we concat ListA and ListB then find the intersection.
ListA+ListB = A + intersection + B +intersection
ListB + ListA = B + intersection + A + intersection
Then we can find the intersections.

If we start traversing the two concatenated lists together , we will reach the intersection at the same time for both since the first 3 parts of both are equal in length as they are same , only order is different.
*/

Node *intersectionOfTwoLinkedLists(Node *l1, Node *l2)
{
    if (l1 == NULL || l2 == NULL)
        return NULL;

    Node *a = l1;
    Node *b = l2;

    while (a != b)
    {
        a = a == NULL ? l1 : a->next;
        b = b == NULL ? l2 : b->next;
    }

    return a;
}