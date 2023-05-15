#include<iostream>
using namespace std;

// Doubly Linked List

class node
{
public:
    int data;
    node* next;
    node* prev;

    node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insertAthead(node* &head,int val){

    node* n = new node(val);
    n->next = head;

    if (head!=NULL){
        head->prev = n;
    }

    head = n;
}

void insertAtTail(node* &head, int val){
    
    if (head==NULL){
        insertAthead(head,val);
        return;
    }
    
    node* n = new node(val);
    node* temp = head;

    while(temp->next!=NULL){
        temp =temp->next;
    }

    temp->next =n;
    n->prev = temp;
}

void display(node* head){
    node* temp =head;
    while(temp!=NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" <<endl;
}

void deleteAtHead(node* &head){
    node* todelete =head;

    head = head->next;
    head->prev =NULL;

    delete todelete;
}

void deletion(node* &head,int pos){
    
    if(pos==1){
        deleteAtHead(head);
        return;
    }

    node* temp = head;
    int count = 1;

    while(count!=pos && temp!=NULL){
        temp = temp->next;
        count++;
    }

    node* todelete =temp;
    temp->prev->next = temp->next;

    if (temp->next!=NULL){
        temp->next->prev = temp->prev;        // Imp
    }
    
    delete todelete;
}

node* reverseLinkedList(node* &head){
    node* prevptr = NULL;
    node* currentptr = head;
    node* nextptr;

    while(currentptr!=NULL){
        nextptr = currentptr->next;
        currentptr->next = prevptr;
        currentptr->prev = nextptr;

        prevptr = currentptr;
        currentptr = nextptr;
    }

    return prevptr;
}


void displayUsingPrev(node* head){

    node* temp =head;
    while(temp->next!=NULL){
        temp = temp->next;
    }

    node* last = temp;
    while(last!=NULL){
        cout << last->data << "<-";
        last = last->prev;
    }

    cout << "NULL" << endl;
}

void pairWithGivenSum(node* head,int x,int p1){

    node* first = head;
    node* temp = head;

    while(temp->next!=NULL && temp->data<= x){
        temp = temp->next;
    }

    node* last = temp;
    while(first->next!=NULL && last->prev!=NULL && first!=last && last->next!=first){

        if (first->data + last->data > x){
            last = last->prev;
        }
        else if (first->data + last->data == x){
            cout << p1 << " " << first->data << " " << last->data << endl;
            first = first->next;
            last = last->prev;
        }
        else{
            first = first->next;
        }

    }

}

node* rotateNnodes(node* &head,int N){

    node* temp = head;
    node* newHead = NULL;
    node* last = NULL;
    int len = 1;

    while(temp->next!=NULL){
        temp = temp->next;
        len++;
    }

    last = temp;
    int S = (len - N);
    temp = head;
    int count = 1;

    while(count!=S){
        temp = temp->next;
        count++;
    }
    newHead = temp;

    newHead->prev->next =NULL;
    newHead->prev = NULL;

    head->prev = last;
    last->next = head;

    return newHead;
}

node* reverseWithGivenSize(node* &head,int N){

    node* prevptr = NULL;
    node* currentptr = head;
    node* nextptr;

    int count = 0;

    while(currentptr!=NULL && count!=N){

        nextptr = currentptr->next;
        currentptr->next = prevptr;
        currentptr->prev = nextptr;

        prevptr = currentptr;
        currentptr = nextptr;
        count++;

    }

    if (nextptr!=NULL){
        head->next = reverseWithGivenSize(nextptr,N);
    }

    return prevptr;
}

void tripletsWithGivenSUm(node* head,int sum){
    
    node* temp = head;
    while(temp->next!=NULL){
        int s = sum-(temp->data);
        pairWithGivenSum(temp->next,s,temp->data);
        temp= temp->next;
    }

}

int main(){

    node* head = NULL;

    // insertion at head and tail
    insertAtTail(head,7);
    insertAthead(head,9);
    insertAtTail(head,6);
    insertAtTail(head,4);
    insertAthead(head,3);
    display(head);
    displayUsingPrev(head);

    // Pair with Given Sum
    pairWithGivenSum(head,13,0);
    
    // reverse the doubly linked list
    node* p =reverseLinkedList(head);
    display(p);
    displayUsingPrev(p);

    // rotate by N nodes
    node* q = rotateNnodes(p,2);
    display(q);

    node* head1 = NULL;
    insertAtTail(head1,7);
    insertAthead(head1,9);
    insertAtTail(head1,6);
    insertAtTail(head1,4);
    insertAthead(head1,8);
    insertAthead(head1,2);
    insertAthead(head1,71);
    insertAthead(head1,44);
    insertAthead(head1,12);
    insertAthead(head1,15);
    insertAthead(head1,28);
    display(head1);

    // reverse with given Size
    node* k = reverseWithGivenSize(head1,3);
    display(k); 

    // Triplte with given sum
    node* head2 = NULL;
    insertAtTail(head2,1);
    insertAtTail(head2,2);
    insertAtTail(head2,4);
    insertAtTail(head2,5);
    insertAtTail(head2,6);
    insertAtTail(head2,8);
    insertAtTail(head2,9);
    display(head2);
    tripletsWithGivenSUm(head2,17);

    return 0;
}