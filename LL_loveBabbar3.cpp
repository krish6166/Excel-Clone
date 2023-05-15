#include<iostream>
#include<unordered_set>
#include<set>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int value){
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

// remove Duplicates m2
void removeDuplicatesm2(node* &head){

    node* temp = head;
    node* temp1 = NULL;

    int val = 0;
    int val1 = 0;
    
    for (temp=head; temp->next!=NULL; temp=temp->next){

        val = temp->data;
        for (temp1=temp; temp1->next!=NULL; temp1=temp1->next){

            val1 = temp1->next->data;
            if (val1==val){
                node* todelete = temp1->next;
                temp1->next = temp1->next->next;
                delete todelete;
            }
        }
    }

}

// remove duplicates by hashing m1
void removeDuplicatesm1(node* &head){

    unordered_set<int> s;
    
    node* curr =head;
    node* prev = NULL;

    while(curr!=NULL){

        int a = curr->data;

        if (s.find(a) != s.end()){
            prev->next = curr->next;
            delete curr;
        }
        else {
            s.insert(a);
            prev = curr;
        }

        curr = prev->next;
    }

}

node* reverseLinkedList(node* &head){

    node* prev = NULL;
    node* curr = head;
    node* nxt;

    while(curr!=NULL){

        nxt = curr->next;
        curr->next = prev;

        prev = curr;
        curr = nxt;
        
    }

    return prev;
}


// add One to a Number represented by linked list
node* addOneToNumber(node* &head){

    // reverse the linked list
    node* newHead = reverseLinkedList(head);
    
    // Add One to it
    node* temp = newHead;
    node* res = newHead;
    int carry = 1,sum = 0;

    while(temp!=NULL){

        sum = carry + temp->data;
        carry = (sum>=10) ? 1 : 0;
        sum = sum %10;

        temp->data = sum;
        temp = temp->next;
    }

    if (carry > 0){
        // in cases like 999 , we wil have carry one 
        insertAtTail(newHead,carry);
    }

    // Again Reverse The Linked List
    node* p = reverseLinkedList(res);

    return p;
}

// Add Two numbers represented by linked list
node* addTwoNumbers(node* head1, node* head2){

    node* head3 = reverseLinkedList(head1);
    node* head4 = reverseLinkedList(head2);

    node* temp1 = head3;
    node* temp2 = head4;

    int p1,p2,sum;
    int carry = 0;

    node* res = NULL;

    while(temp1!=NULL && temp2!=NULL){
        
        p1 = temp1->data;
        p2 = temp2->data;
        sum = p1 + p2 + carry;
        carry = (sum>=10) ? 1 : 0;
        sum = sum%10;

        insertAtTail(res,sum);
        temp1 = temp1->next;
        temp2= temp2->next;

    }

    while(temp1!=NULL){
        sum = carry + temp1->data;
        carry = (sum>=10)?1:0;
        sum = sum%10;

        insertAtTail(res,sum);
        temp1 = temp1->next;
    }

    while(temp2!=NULL){
        sum = carry + temp2->data;
        carry = (sum>=10)?1:0;
        sum = sum%10;

        insertAtTail(res,sum);
        temp2 = temp2->next;
    }

    if (carry>0){
        insertAtTail(res,carry);
    }

    return (reverseLinkedList(res));
}

int main(){

    node* head = NULL;
    int arr[] = {1,2,6,1,1,1,2,2,3,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int i=0;i<n;i++){
        insertAtTail(head,arr[i]);
    }
    display(head);


    // 1) remove Duplicates : 2 methods

    // removeDuplicatesm2(head);
    removeDuplicatesm1(head);
    display(head);

    // 2) add 1 to number
    node* head1 = addOneToNumber(head);
    display(head1);

    // 3) add Two Number
    node* numOne = NULL;
    int arr1[] = {4,2,1};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    for (int i=0;i<n1;i++){
        insertAtTail(numOne,arr1[i]);
    }
    node* numTwo = NULL;
    int arr2[] = {5,6,1,4};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    for (int i=0;i<n2;i++){
        insertAtTail(numTwo,arr2[i]);
    }
    display(numOne);
    display(numTwo);
    node* head2 = addTwoNumbers(numOne,numTwo);
    display(head2);

    return 0;
}