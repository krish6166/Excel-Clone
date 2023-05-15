#include<iostream>
using namespace std;

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

    if (head != NULL){
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
    
    if(pos == 1){
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
        temp->next->prev = temp->prev;
    }
    
    delete todelete;
}

int getlength(node *head){

    node* temp = head;
    int count = 0;

    while(temp!=NULL){
        temp=temp->next;
        count++;
    }

    return count;
}

// Append K nodes at starting
node* kappend(node* &head,int k){

    node* newhead;
    node* newtail;
    node* tail = head;
    
    int l = getlength(head);
    k = k%l;
    int count=1;

    while(tail->next!=NULL){
        
        if (count == (l-k)){
            newtail = tail;
        }
        if (count == (l-k+1)){
            newhead = tail;
        }
        tail = tail->next;
        count++;
    }

    newtail->next =NULL;
    tail->next = head;
    
    return newhead;
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
    
    node* krish = kappend(head,3);
    display(krish);

    deletion(krish,2);
    display(krish);

    deletion(krish,1);
    display(krish);

    return 0;
}