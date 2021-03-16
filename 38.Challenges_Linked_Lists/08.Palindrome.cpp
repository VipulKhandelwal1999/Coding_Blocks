/*
Check if a linked list is a palindrome.( Boolean return type )

Input Format
Add N space separated elements in the list

Constraints
None

Output Format
Boolean answer( true or false)

Sample Input
5
1 2 3 6 8
Sample Output
false
*/
/*
SOLUTION:-
The Idea is to Use Recursion to check whether the LinkedList is palindrome or not.
To check Palindrome we have used 2 Variable which points to the starting and end of the List.
As The Linked List is singly so we can go from one node to next node by moving frwd but we cannot move backwards in the LinkedList.
To move our pointing Variable backwards we are using Recursion.
To move our pointing variable frwd we are using a class which is Heapmover so that the incrementation could Exist on recursive stacks( Memory here ).
To check Palindrome we have Used a Headmover class so that the Starting pointer could increment and its update value could reflect on the recursive calls also.
*/
 private class heapmover {
        Node n1;
    }
    public boolean palindrome() {
        heapmover mover = new heapmover();
        mover.n1 = this.head;
        return palindrome(mover, this.head, 0);
    }
    public boolean palindrome(heapmover mover, Node n2, int cnt) {
        if (n2 == null) {
            return true;
        }
        boolean b = palindrome(mover, n2.next, cnt + 1);
        if (n2 != null && cnt > this.size / 2) {
            if (mover.n1.data != n2.data) {
                return false;
            }
        }
        mover.n1 = mover.n1.next;
        return b;
    }


    // OR

    #include<bits/stdc++.h>
using namespace std;

class node {

    public:
        int data;
        node *next;

        node(int d){
            data = d;
            next = NULL;
        }
};

void insertAtTail(node* &head, int data){
    if(head == NULL){
        head = new node(data);
        return;
    }
    node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    tail->next = new node(data);
    return;
}

void buildList(node* &head, int n){
    int data;
    for(int i=0; i<n; i++){
		cin >> data;
        insertAtTail(head, data);
    }
}

void reverse(node* &head, int n){
	node* temp = head;
	int x = n/2;
	if(n&1){
		for(int i=0; i<x; i++){
			temp = temp->next;
		}
		node* prev = temp;
		temp = temp->next;
		prev->next = NULL;

		node* current = temp;
    	node* pre = NULL;
    	node* n;
		while(current != NULL){
			n = current->next;
			current->next = pre;
			pre = current;
			current = n;
		}
		temp = pre;
		prev->next = temp;
	}
	else{
		for(int i=0; i<x-1; i++){
			temp = temp->next;
		}
		node* prev = temp;
		temp = temp->next;
		prev->next = NULL;

		node* current = temp;
    	node* pre = NULL;
    	node* n;
		while(current != NULL){
			n = current->next;
			current->next = pre;
			pre = current;
			current = n;
		}
		temp = pre;
		prev->next = temp;
	}
}
node* mid_point_fast_runner(node* head){

    if(head == NULL || head->next == NULL){
        return head;
    }

    node* slow = head;
    node* fast = head->next;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
bool check_palindrome(node* head, int n){
	node *temp = head;
	node *mid = mid_point_fast_runner(head);
		node* f = mid->next;
		for(int i=0; i<n/2; i++){
			if(temp->data != f->data){
				return false;
			}
			temp = temp->next;
			f = f->next;
		}
		return true;
	
}
void print(node* head){
    node* temp = head;

    while(temp != NULL){
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << endl;
}
int main(){

	int n;
	cin >> n;
	node *head = NULL;
	buildList(head, n);
	reverse(head, n);
	bool ans = check_palindrome(head, n);
	if(ans)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	return 0;
}