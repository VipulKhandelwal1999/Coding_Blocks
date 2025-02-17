/*
Given the head pointer to a linked list , complete the function to check whether there is a cycle present in the linked list. If so , modify the linked list to remove the cycle.

Note : You are only supposed to update the designated function. Do not change/alter the remaining code or your program may not work.

Input Format
Your function accepts one single argument that is the head pointer to the linked list.

Constraints
Your function should run in O(n) time.

Output Format
Your function should return a boolean value - True/False , indicating the presence of the cycle.
True if cycle is present, False otherwise.
If true , remove the cycle as well.

Sample Input
Consider a linked list like 
1 -> 2 -> 3
     ^    |
     |    v
     5<-  4
Sample Output
Your function should return True for the above linked list and remove the cycle as well. <br>
The new linked list should look like - 1->2->3->4->5-> NULL
Explanation
Clearly there is a cycle present. We return true to indicate it and remove it.
Use Floyd cycle detection and removal algorithm to solve this problem.
*/

bool floydCycleRemoval(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return false;
    }
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL && fast != slow)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast == NULL || fast->next == NULL)
    {
        //No cycle present
        return false;
    }

    if (fast->next == head)
    {
        fast->next = NULL;
        return true;
    }

    slow = head;
    fast = fast->next;
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
    return true;
}
