#include<bits/stdc++.h>
using namespace std;

class node {

    public:
        int data;
        node *next;

        //Constructor
        node(int d){
            data = d;
            next = NULL;
        }
};
/*
class LinkedList{
    node *head;
    node *tail;

    public:
        LinkedList(){
            head = NULL;
            tail = NULL;
        }

        void insert(){

        }
};
*/

//Passing a pointer variable by reference
void insertAtHead(node* &head, int data){

    node *n = new node(data);
    n->next = head;
    head = n;

}
//Passed By Value
void print(node* head){
    node* temp = head;

    while(temp != NULL){
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << endl;
}
//We can also do
/*
void print(node* head){
    while(head != NULL){
        cout << head -> data << " -> ";
        head = head -> next;
    }
    cout << endl;
}
*/
int length(node* head){
    int len = 0;
    while(head != NULL){
        head = head->next;
        len++;
    }
    return len;
}

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

void insertInMiddle(node* &head, int data, int p){
    if(head == NULL || p == 0){
        insertAtHead(head, data);
    }
    else if(p > length(head)){
        insertAtTail(head, data);
    }
    else{
        //Insert in the middle
        //Take p-1 jumps
        int jump = 1;
        node* temp = head;
        while(jump <= p-1){
            temp = temp->next;
            jump += 1;
        }
        node* n = new node(data);
        n->next = temp->next;
        temp->next = n;
    }
}

void deleteAtHead(node* &head){
    if(head == NULL)
        return;
    node* temp = head;
    head = head->next;
    delete temp;
    return;
}
void deleteAtTail(node* &head){

    node* prev = NULL;
    node* temp = head;

    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    delete temp;
    prev->next = NULL;
    return;
}

void deleteInTheMiddle(node* &head, int p){
    if(head == NULL)
        return;
    if(p == 0){
        deleteAtHead(head);
        return;
    }
    if(p>length(head))
        return;
    //Insert in the middle
    //Take p-1 jumps
    int jump = 1;
    node* temp = head;

    while(jump <= p-1){
        temp = temp->next;
        jump += 1;
    }
    node* prev = temp->next;
    temp->next = prev->next;
    delete prev;
}

void buildList(node* &head){
    int data;
    cin >> data;

    while(data != -1){
        insertAtTail(head, data);
        cin >> data;
    }
}
istream& operator>>(istream &is, node* &head){
    buildList(head);
    return is;
}

ostream& operator<<(ostream &os, node* head){
    print(head);
    return os;
}

void reverse(node* &head){
    node* current = head;
    node* prev = NULL;
    node* n;
    while(current != NULL){
        //Save the next node
        n = current->next;
        //Make the current node point to prev
        current->next = prev;
        //Just update prev and current
        prev = current;
        current = n;
    }
    head = prev;
}

node* reverse_recursive(node* head){

    //Base Case
    if(head->next == NULL || head == NULL)
        return head;
    //Recursive Case
    node* smallHead = reverse_recursive(head->next);
    node* current = head;
    current->next->next = current;
    current->next = NULL;
    return smallHead;

}

node* mid_point_fast_runner(node* head){

    if(head == NULL || head->next == NULL){
        return head;
    }

    node* slow = head;
    node* fast = head;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

node* kth_node_fast_runner(node* head, int k){

    int count = 0;
    node* slow = head;
    node* fast = head;

    while(count < k){
        fast = fast->next;
        count++;
    }

    while(fast != NULL){
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}
node* merge(node* a, node* b){
    if(a == NULL)
        return b;
    else if(b == NULL)
        return a;
    node* c;

    //Compare a and b for smaller element
    if(a->data < b->data){
        c = a;
        c->next = merge(a->next, b);
    }
    else{
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}

node *mergeSort(node *head){
    //base case
    if(head == NULL or head->next==NULL)
        return head;

    //recursive case
    //1.Break
    node *mid = mid_point_fast_runner(head);
    node *a = head;
    node *b = mid->next;

    mid->next = NULL;

    //2.rec sort the two parts
    a = mergeSort(a);
    b = mergeSort(b);

    //3. Merge Them
    node *c = merge(a,b);
    return c;
}

int main(){

    node* head;
    cin >> head;
    cout << head << endl;
    return 0;
}
