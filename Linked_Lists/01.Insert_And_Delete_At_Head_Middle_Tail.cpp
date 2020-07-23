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

int main(){

    node* head = NULL;
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtTail(head, 8);
    insertInMiddle(head, 2, 3);
    insertInMiddle(head, 1, 4);
    insertInMiddle(head, 6, 5);
    print(head);
    deleteAtHead(head);
    deleteAtTail(head);
    deleteInTheMiddle(head, 1);
    print(head);

    return 0;
}
