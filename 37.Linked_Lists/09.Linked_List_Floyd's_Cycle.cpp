#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* next;

    //Constructor
    node(int d){
        data = d;
        next = NULL;
    }
};

/*
class LinkedList{
    node*head;
    node*tail;
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
void insertAtHead(node*&head,int data){
    node*n = new node(data);
    n->next = head;
    head = n;
}

int length(node*head){

    int len=0;
    while(head!=NULL){
        head = head->next;
        len += 1;
    }
    return len;
}

void insertAtTail(node*&head,int data){

    if(head==NULL){
        head = new node(data);
        return;
    }
    node*tail = head;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    tail->next = new node(data);
    return;
}

void insertInMiddle(node*&head,int data,int p){

    if(head==NULL||p==0){
        insertAtHead(head,data);
    }
    else if(p>length(head)){
        insertAtTail(head,data);
    }
    else{
        //Insert in the middle
        //Take p-1 jumps
        int jump=1;
        node*temp = head;
        while(jump<=p-1){
            temp = temp->next;
            jump += 1;
        }

        node*n = new node(data);
        n->next = temp->next;
        temp->next = n;

    }
}

bool searchRecursive(node*head,int key){
    if(head==NULL){
        return false;
    }
    //Rec Case
    if(head->data ==key){
        return true;
    }
    else{
        return searchRecursive(head->next,key);
    }
}
bool searchIterative(node*head,int key){

    while(head!=NULL){
        if(head->data==key){
            return true;
        }
        head = head->next;
    }
    return false;
}

void print(node*head){
    //node*temp = head;

    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;
}
void deleteAtHead(node*&head){
    if(head==NULL){
        return;
    }
    node*temp = head;
    head = head->next;
    delete temp;
    return;
}

void deleteInTheMiddle(node*head,int p){
    //Homework
}

node* midPoint(node*head){
    if(head==NULL||head->next==NULL){
        return head;
    }

    node*slow = head;
    node*fast = head->next;

    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;

}

void reverse(node*&head){

    node*C = head;
    node*P = NULL;
    node*N;

    while(C!=NULL){
        //Save the next node
        N = C->next;
        //Make the current node point to prev
        C->next = P;
        //Just update prev and current
        P = C;
        C= N;
    }
    head = P;
}

node* reverseRec(node*head){
    //Base Case
    if(head->next==NULL||head==NULL){
        return head;
    }
    //Rec Case
    node*smallHead = reverseRec(head->next);
    node*C = head;
    C->next->next = C;
    C->next = NULL;
    return smallHead;

}

node* mid(node*head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    node*slow = head;
    node*fast = head->next;

    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

void buildList(node*&head){

    int data;
    cin>>data;

    while(data!=-1){
        insertAtTail(head,data);
        cin>>data;
    }
}

istream& operator>>(istream &is,node*&head){
    buildList(head);
    return is;
}

ostream& operator<<(ostream &os,node*head){
    print(head);
    return os;
}

node* merge(node*a,node*b){
  if(a==NULL){
      return b;
  }
  else if(b==NULL){
      return a;
  }

  node*c;

  //Compare a and b for smaller element
  if(a->data < b->data){
      c = a;
      c->next = merge(a->next,b);
  }
  else{
      c = b;
      c->next = merge(a,b->next);
  }
  return c;
}



node* mergeSort(node*head){
    //Base Case
    if(head==NULL||head->next==NULL){
        return head;
    }
    //Rec Case
    //1. Mid point
    node*mid = midPoint(head);

    node*a = head;
    node*b = mid->next;
    mid->next = NULL;

    //2. Recusively Sort
    a = mergeSort(a);
    b = mergeSort(b);

    //3. Merge a and b
    node* c = merge(a,b);
    return c;
}

bool detectCycle(node *head){
    node *slow = head;
    node *fast = head;

    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow){
            return true;
        }
    }
    return false;
}

bool detectAndRemoveLoop(node *head){
    node *slow = head;
    node *fast = head;

    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow){
            removeLoop(slow, head);
            return true;
        }
    }
    return false;
}

void removeLoop(struct Node* loop_node, struct Node* head)
{
    struct Node* ptr1 = loop_node;
    struct Node* ptr2 = loop_node;

    // Count the number of nodes in loop
    unsigned int k = 1, i;
    while (ptr1->next != ptr2) {
        ptr1 = ptr1->next;
        k++;
    }

    // Fix one pointer to head
    ptr1 = head;

    // And the other pointer to k nodes after head
    ptr2 = head;
    for (i = 0; i < k; i++)
        ptr2 = ptr2->next;

    /*  Move both pointers at the same pace,
      they will meet at loop starting node */
    while (ptr2 != ptr1) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    // Get pointer to the last node
    while (ptr2->next != ptr1)
        ptr2 = ptr2->next;

    /* Set the next node of the loop ending node
      to fix the loop */
    ptr2->next = NULL;
}


int main() {
    node*head = NULL;
    node*head2 = NULL;

    cin>>head;
    cout<<head;

    head = mergeSort(head);
    cout<<head;


    return 0;
}
