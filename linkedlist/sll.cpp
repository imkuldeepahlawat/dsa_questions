// singly linked list
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    // creating constructor
    node(int data){
        this->data = data;
        this->next = NULL;
    }
    // creating destructor
    ~node(){
        int value = this->data;
        // memory free
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<endl<<"Memory free"<<endl;
    }
};
// for insertion in head
void hi(node* &head,int d){
    node* temp = new node(d);
    temp->next = head;
    head = temp;
}
// tail insertion
void ti(node* &tail,int d){
    node* temp = new node(d);
    tail->next = temp;
    tail = temp;
    cout<<endl<<tail->data<<endl;
}

void pi(node* &tail,node* &head,int position,int d){
    int cnt = 1;

    if(position == 1){
        hi(head,d);
        return ;
    }
    node* temp = head;
    while (cnt < position-1){
        temp=temp->next;
        cnt++;
    }
    
    if(temp == NULL){
        ti(tail,d);
    }

    node* n = new node(d);
    n->next = temp->next;
    temp->next = n;

    
}

// delete  any element from linked list
void dll(node*&head,int position){
    if(position == 1){
        node* temp = head;
        head = head->next;
        delete temp;
        return ;
    }
    else{
        // deleting any middle or last element
        node* curr = head;
        node* prev = NULL;
        int cnt = 1;
        while(cnt<position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr = NULL;
        delete curr;
    }
}
// print function for linked list
void pll(node* &head){
    node* n = head;

    while(n != NULL){
        cout<<n->data<<" ";
        n = n->next;
    }
    cout<<endl;
}


int main(){
    // creating node
    node* node1 = new node(20);
    // creating pointer for head
    node* head = node1;
    node* tail = node1;
    hi(head,10);
    ti(tail,30);
    pll(head);
    pi(tail,head,3,25);
    pll(head);dll(head,3);
    pll(head);
}