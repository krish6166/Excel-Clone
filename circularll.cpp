#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node* next;

    node(int val){
        data =val;
        next = NULL;
    }
};

void insertAtHead(node* &head,int val){

    node* n = new node(val);
    
    if (head == NULL){
        n->next = n;     // Imp*
        head = n;
        return;
    }
    node* temp =head;

    while(temp->next!=head){
        temp =temp->next;
    }

    temp->next =n;
    n->next =head;
    head = n;

}

void insertAtTail(node* &head,int val){

    if (head== NULL){
        insertAtHead(head, val);
        return;
    }
    node* temp = head;
    node* n =new node(val);

    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next =n;
    n->next =head;
}

void display(node* head){
    node* temp =head;
    do
    {
    cout << temp->data << " ";
    temp = temp->next;
    } while (temp!=head);
    
    cout << endl;
}

void deleteAthead(node* &head){
    node* temp =head;
    while(temp->next!=head){
        temp=temp->next;
    }
    node* todelete =head;
    temp->next = head->next;
    head = head->next;

    delete todelete;
}

void deletion(node* &head,int pos){

    if (pos == 1){
        deleteAthead(head);
        return;
    }
    node* temp =head;
    int count = 1;
    while(count!=(pos-1)){
        temp = temp->next;
        count++;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;

}

int main(){

    node* head = NULL;

    insertAtHead(head, 5);
    insertAtHead(head, 6);
    insertAtHead(head, 7);
    insertAtHead(head, 8);
    display(head);

    // insertAtTail(head,5);
    // insertAtTail(head,6);
    // insertAtTail(head,7);
    // insertAtTail(head,8);
    // display(head);

    // deletion(head,2);
    // display(head);
    
    return 0;
}