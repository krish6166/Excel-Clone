#include<iostream>
#include<unordered_set>
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

// Intersection point of two linked list m1: O(m+n)
int intersectionPointM1(node* &head1,node* &head2){

    node* ptr1 = head1;
    node* ptr2 = head2;

    while(ptr1!=ptr2){

        if (ptr1==ptr2){
            return ptr1->data;
        }

        if (ptr1==NULL){
            ptr1=head2;
        }

        if (ptr2==NULL){
            ptr2 = head1;
        }

        ptr1=ptr1->next;
        ptr2=ptr2->next;

    }

    return ptr1->data;
}

// intersection point using heashing :time O(n) and space O(m) 
// Not Efficient
int intersectionPointM2(node* head1,node* head2){

    unordered_set<node*> s1;

    node* temp1 = head1;

    // insert all ele of first list in set
    while(temp1!=NULL){
        s1.insert(temp1);
        temp1=temp1->next;
    }

    temp1 = head2;
    while(temp1!=NULL){
        
        // if ele is found in second list
        if (s1.find(temp1)!=s1.end()){
            return temp1->data;
        }
        temp1=temp1->next;
    }

    return -1;
}

int getLength(node* head){
    int length = 1;
    while(head!=NULL){
        head=head->next;
        length++;
    }
    return length;
}

int intersectionPointM3(node* head1,node* head2){

    int l1 = getLength(head1);
    int l2 = getLength(head2);

    int d = (l1>=l2)?(l1-l2):(l2-l1);

    if (l1>l2){
        node* temp1 = head1;
        node* temp2 = head2;

        int count = 0;
        while(count!=d){
            temp1 = temp1->next;
            count++;
        }

        while(temp1!=NULL && temp2!=NULL){

            if (temp2==temp1){
                return temp1->data;
            }
            
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    else {

        node* temp1 = head2;
        node* temp2 = head1;

        int count = 0;
        while(count!=d){
            temp1 = temp1->next;
            count++;
        }

        while(temp1!=NULL && temp2!=NULL){

            if (temp2==temp1){
                return temp1->data;
            }
            
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

    }

    return -1;
}

int main(){

    // Intersection point of two linked list
    node* head1 = NULL;
    node* head2 = NULL;
    
    // head1 : 1,2,3,4,5,6
    head1=new node(1);
    head1->next = new node(2);
    head1->next->next = new node(3);
    head1->next->next->next = new node(4);
    head1->next->next->next->next = new node(5);
    head1->next->next->next->next->next = new node(6);

    // head2 : 10,9,8,7,4,5,6
    head2 = new node(10);
    head2->next = new node(9);
    head2->next->next = new node(8);
    head2->next->next->next = new node(7);
    head2->next->next->next->next = head1->next->next->next;
    head2->next->next->next->next->next = head1->next->next->next->next;
    head2->next->next->next->next->next->next = head1->next->next->next->next->next;

    display(head1);
    display(head2);

    cout << intersectionPointM1(head1,head2) << endl;

    cout << intersectionPointM2(head1,head2) << endl;

    cout << intersectionPointM3(head1,head2) << endl;
    
    return 0;

}