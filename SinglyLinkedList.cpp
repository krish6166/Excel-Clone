#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;

    node (int value){
        data = value;
        next = NULL;
    }
};

void display(node* head){

    node* temp = head;

    while(temp!=NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }

    cout << "NULL"<< endl;

}

void insertAtTail(node* &head,int val){

    node* temp = head;
    node* n = new node(val);

    if (head==NULL){
        head=n;
        return;
    }

    while(temp->next!=NULL){
        temp = temp->next;
    }

    temp->next = n;
    
}

void deletionByValue(node* &head,int val){

    node* temp = head;
    while(temp->next->data != val){
        temp = temp->next;
    }

    node* todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;

}

node* reverseLinekedListIterative(node* &head){

    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    while(currptr!=NULL){
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }

    return prevptr;

}

node* reverseLinekedListRecursive(node* &head){

    if(head==NULL || head->next==NULL){
        return head;
    }

    node* newhead = reverseLinekedListRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return newhead;

}

node* reversek(node* &head,int k){

    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    int count =0;
    while(currptr!=NULL && count< k){
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
        count++;
    }

    if (nextptr!=NULL){
        head->next = reversek(nextptr,k);
    }

    return prevptr;
}

void createCycle(node* &head, int pos){

    node* temp = head;
    node* cycleNode;
    int count = 1;
    
    while(temp->next!=NULL){

        if (count == pos){
            cycleNode = temp;
        }
        temp= temp->next;
        count++;
    }

    temp->next = cycleNode;
}

// Floyds Algorithm (Hare and Tortoise)
bool detectCycle(node* head){

    node* slow = head;
    node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(slow == fast){
            return true;
        }
    }

    return false;
}

// Floyds Algorithm (Hare and Tortoise)
void removeCycle(node* head){
    node* slow =head;
    node* fast = head;

    do
    {
        slow=slow->next;
        fast=fast->next->next;
    } while (slow!=fast);
    

    slow = head;

    while(fast->next!=slow->next){
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = NULL;

}


int main(){

    // 1) Creation Of Linked List
    node* head = NULL;
    int arr[]={1,2,3,7,56,9,10,11,12,13,14,15,16,17,18,19};
    int size = sizeof(arr)/sizeof(arr[0]);

    for (int i=0; i<size; i++){
        insertAtTail(head,arr[i]);
    }
    display(head);

    // 2) Deletion of particular node , when val of thet node is given
    deletionByValue(head,7);
    deletionByValue(head,56);
    display(head);

    // 3) Reverse the Linked List :

    // A) Iterative Way
    node* newhead = reverseLinekedListIterative(head);
    display(newhead);

    // B) Recursive Way
    node* k = reverseLinekedListRecursive(newhead);
    display(k);

    // 4) Reverse K node 
    int p = 2;
    node* s = reversek(head,p);
    display(s);

    // 5) Flyods Algorithm : detection of cycle
    cout << detectCycle(s) << endl;
    createCycle(s,5);
    cout << detectCycle(s) << endl;

    //display(s);
    removeCycle(s);
    cout << detectCycle(s) << endl;

    return 0;
}