/*
Given a linked list with n nodes. Sort the linked list using insertion sort.

Input Format
First line contains the number of nodes in the linked list n and then next line contains n space separated integers representing the node values of the linked list.

Constraints
n < 30

Output Format
Print the linked list after sorting it using insertion sort.

Sample Input
5
2 3 4 1 5
Sample Output
1 2 3 4 5
Explanation
None


SOLUTION:-
Algorithm:

1) Create an empty sorted (or result) list

2) Traverse the given list, do following for every node.

        a) Insert current node in sorted way in sorted or result list.
3) Change head of given linked list to head of sorted (or result) list.
*/

#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node * next;    //self referential class

    Node(int num){
        data = num;
        next = NULL;    //NULL is a macro
    }
};

Node *copyList( Node *head)
{
    if( head == NULL ) return NULL;

    Node *copy = new Node( head -> data );
    copy -> next = copyList(head -> next);
    return copy;
}

Node *addBehind(Node *head , Node *newNode)
{
    if( head == NULL )
    {
        return newNode;
    }

    Node *temp = head;

    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }

    temp -> next = newNode;

    return head;
}


void addToFront(Node* &head, Node* nodeToAdd){
    if (head == NULL){
        head = nodeToAdd;
        return;
    }

    nodeToAdd->next = head;
    head = nodeToAdd;
}

Node* takeInput()
{
    int num;
    Node * head = NULL;

    while(cin >>num && num != -1)
    {
        Node *newNode = new Node(num);
        head = addBehind(head, newNode);
    }

    return head;
}

Node* takeInput2( int num )
{
    Node * head = NULL;

    int x;

    for(int i = 0 ; i < num ; ++i)
    {
        cin >> x;
        Node *temp = new Node(x);
        head = addBehind( head , temp);
    }

    return head;
}

void print(Node* head){
    //prints the Linked list
    Node * tmp = head;
    while(tmp != NULL){
        //I have not reached the end
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
using namespace std;

Node *insertProperly( Node *head , Node *temp )
{
    if( head == NULL || head -> data >= temp -> data )
    {
        temp -> next = head;
        return temp;
    }

    Node *parse = head;

    while( head -> next != NULL && head -> next -> data < temp -> data  )
    {
        head = head -> next;
    }

    temp -> next = head -> next;
    head -> next = temp;

    return parse;
}

Node *insertionSort( Node *temp )
{
    Node *sorted = NULL;

    while( temp != NULL )
    {
        Node *temp2 = temp -> next;
        sorted = insertProperly( sorted , temp );
        temp = temp2;
    }

    return sorted;
}

int main()
{    
    int n;
    cin >> n;
    Node *head = takeInput2(n);
    head = insertionSort(head);
    print(head);
    return 0;
}
