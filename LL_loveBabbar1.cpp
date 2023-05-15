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
    
    n->next =head;
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

// middle of the nodes
void middleOfLinkedList(node* &head){

    node* temp = head;

    // Lets first find out the length
    int l=1,p;
    while(temp->next!=NULL){
        temp = temp->next;
        l++;
    }

    if (l%2==0){
        // length is even
        p = l/2;
        temp = head;
        l=1;
        while(l !=p){
            temp = temp->next;
            l++;
        }
        cout << temp->data << " " << temp->next->data << endl;
        return;
    }
    else{
        // length is odd
        p = l/2 +1;
        temp = head;
        l=1;
        while(l !=p){
            temp = temp->next;
            l++;
        }
        cout << temp->data << endl;
        return;
    }

}

// check if the linked list is circular or not
bool isCircular(node* head){

    // empty linked list is circular
    if (head == NULL){
        return true;
    }

    node* temp = head;
    while(temp->next!=NULL && temp->next!=head){
        temp=temp->next;
    }

    return (temp->next == head);
}

void makeCircular(node* &head){
    node* temp = head;

    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next = head;
    return;
}

void removeCircular(node* &head){
    node* temp = head;

    while(temp->next!=head){
        temp=temp->next;
    }

    temp->next = NULL;
    return;
}

void exchangeFirstAndLast(node* &head){
    node* temp = head;
    node* p = head;

    while(temp->next->next!=NULL){
        temp = temp->next;
    }

    head = temp->next;
    temp->next->next = p->next;
    temp->next = p;
    p->next = NULL;
    
}

int main(){

    // Creating the linked list and displaying
    node* head = NULL;
    int arr[] = {1,2,3,9,6,5,8,6,4,1,7};
    for (int i=0;i<11;i++){
        insertAtTail(head,arr[i]);
    }
    display(head);

    // print the middle of the linked list
    middleOfLinkedList(head);

    //checking the circular linked list
    cout << isCircular(head) << endl;
    makeCircular(head);
    cout << isCircular(head) << endl;
    removeCircular(head);
    
    exchangeFirstAndLast(head);
    display(head);
    
    return 0;
}