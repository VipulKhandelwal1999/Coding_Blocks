/*
Given 2 sorted linked lists , merge the two given sorted linked list and print the final Linked List.

Input Format
First Line contains T the number of test cases.
For each test case :
Line 1 : N1 the size of list 1
Line 2 : N1 elements for list 1
Line 3 : N2 the size of list 2
Line 4 : N2 elements for list 2

Constraints
1 <= T <= 1000
0<= N1, N2 <= 10^6
-10^7 <= Ai <= 10^7

Output Format
For each testcase , print the node data of merged linked list.

Sample Input
1
4
1 3 5 7
3
2 4 6
Sample Output
1 2 3 4 5 6 7 
Explanation
The two lists after merging give the sorted output as [1,2,3,4,5,6,7] .
*/
#include<bits/stdc++.h>
using namespace std;

class LinkedList {
	public:
		int data;
		LinkedList* next;

		LinkedList(int d){
			data = d;
			next = NULL;
		}
};

void insert(LinkedList* &head, int d){
	LinkedList* temp = head;
	if(temp == NULL){
		head = new LinkedList(d);
	}
	else{
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = new LinkedList(d);
	}
}

void printLinkedList(LinkedList* head){
	while(head->next != NULL){
		cout << head->data << " ";
		head = head->next;
	}
	cout << head->data;
}

void reverseAtK(LinkedList* &head, int k){
	
	LinkedList* temp = head;
	LinkedList* prev = head;
	LinkedList* fast = head;
	int count = 1;
	while(count < k){
		fast = fast->next;
		count++;
	}
	fast = fast->next;
	while(fast->next != NULL){
		fast = fast->next;
		prev = prev->next;
	}
	temp = prev->next;
	prev->next = NULL;
	fast->next = head;
	head = temp;
}

LinkedList* mergeSorted(LinkedList* head1, LinkedList* head2){
	if(head1 == NULL){
		return head2;
	}
	if(head2 == NULL){
		return head1;
	}
	LinkedList* temp;
	if(head1->data < head2->data){
		temp = new LinkedList(head1->data);
		temp->next = mergeSorted(head1->next, head2);
	}
	else{
		temp = new LinkedList(head2->data);
		temp->next = mergeSorted(head1, head2->next);
	}

	return temp;
}

int main() {

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		LinkedList* head = NULL;
		for(int i=0; i<n; i++){
			int x;
			cin >> x;
			insert(head, x);
		}
		LinkedList* head1 = NULL;
		int k;
		cin >> k;
		for(int i=0; i<k; i++){
			int x;
			cin >> x;
			insert(head1, x);
		}

		LinkedList* ans = mergeSorted(head, head1);
		printLinkedList(ans);
		cout << endl;
	}
	return 0;
}