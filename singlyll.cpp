#include<iostream>
using namespace std;

class node
{

public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
    
};

void insertAthead(node* &head,int val){

    node* n =new node(val);

    if (head==NULL){
        head = n;
        return;
    }
    
    n->next = head;
    head = n;
}

void insertAtTail(node* &head,int val){
    
    node* n = new node(val);
    node* temp =head;

    if (head==NULL){
        head= n;
        return;
    }

    while(temp->next!=NULL){
        temp =temp->next;
    }

    temp->next = n;
}

void display(node* head){

    node* temp=head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp=temp->next;
    }
    cout << endl;

}

// merge two sorted linked list
node* mergell(node* head1 , node* head2){

    node* demo = new node(1);
    node* k = demo;

    node* temp1 = head1;
    node* temp2 = head2;

    while(temp1!=NULL && temp2!=NULL){

        if (temp1->data < temp2->data){
            demo->next = temp1;
            temp1= temp1->next;
        }
        else
        {
            demo->next = temp2;
            temp2 = temp2->next;
        }
        demo = demo->next;

    }

    if (temp1==NULL){

        while(temp2!=NULL){
            demo->next = temp2;
            temp2 = temp2->next;
            demo = demo->next;
        }

    }

    if (temp2==NULL){

        while(temp1!=NULL){
            demo->next = temp1;
            temp1 = temp1->next;
            demo = demo->next;
        }
        
    }

    return k->next;
}

int main(){

    node* head1= NULL;
    insertAtTail(head1,6);
    insertAtTail(head1,8);
    insertAtTail(head1,10);
    insertAtTail(head1,12);
    insertAtTail(head1,15);
    insertAtTail(head1,100);
    insertAtTail(head1,102);
    insertAtTail(head1,106);

    node* head2= NULL;
    insertAtTail(head2,1);
    insertAtTail(head2,5);
    insertAtTail(head2,9);
    insertAtTail(head2,11);
    insertAtTail(head2,14);

    node* p = mergell(head1,head2);
    display(p);

    return 0;
}