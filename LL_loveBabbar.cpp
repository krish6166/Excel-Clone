#include<iostream>
#include<climits>
#include<stack>
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

// take the last node at the front of the linked list
void lastToFront(node* &head){

    node* temp = head;

    while(temp->next->next!=NULL){
        temp = temp->next;
    }

    temp->next->next = head;
    head = temp->next;

    temp->next = NULL;

}

// Check the palindrome
bool isPalindrome(node* &head){

    node* temp = head;
    stack<int> s;

    while(temp != NULL){
        s.push(temp->data);
        temp = temp->next;
    }

    temp=head;

    while(temp != NULL){
        if (s.top() != temp->data){
            return false;
        }
        temp = temp->next;
        s.pop();
    }
    return true;

}

// deleting the entire linked list
void deleteLinekedList(node* &head){

    node* current = head;
    node* next = NULL;

    while(current->next!=NULL){
        next = current->next;
        delete current;
        current = next;
    }

    head = NULL;
}

// removing the duplicates in the sorted linked list
void removeDuplicates(node* &head){
    
    node* current = head;
    node* next;

    if (current==NULL){
        return;
    }

    while(current->next!=NULL){
        
        if (current->data == current->next->data ){
            next = current->next->next;
            delete current->next;
            current->next = next;
        }
        else{
            current = current->next;
        }
    }
}

int main(){

    // Creating the linked list and displaying
    node* head = NULL;
    int arr[] = {1,2,3,4,5,5,4,3,2,1};
    for (int i=0;i<10;i++){
        insertAtTail(head,arr[i]);
    }
    display(head);

    // palindrome checking
    bool p = isPalindrome(head);
    cout << p << endl;

    // delete the entire linked list
    deleteLinekedList(head);
    display(head);

    // Creating the another linked list
    node* head1 = NULL;
    int arr1[] = {1,2,2,4,5,6,6,6,9,10};
    for (int i=0;i<10;i++){
        insertAtTail(head1,arr1[i]);
    }
    display(head1);

    // Removing the duplicates in an array
    removeDuplicates(head1);
    display(head1);

    return 0;
}