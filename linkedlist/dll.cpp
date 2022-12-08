#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    // creating constructor
    node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    // creating destructor
    ~node(){
        // int val = this->data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
    }
};
// counting lenght
int getlinkedlistlenght(node* head){//taking input as head
    int len = 0;//initialise len variable
    node* temp = head;//creating temporary node who is pointing to head address
    //counting until temp is NULL
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len; //returning lenght
}
// insertion on head side
void hi(node* &head,node* &tail,int d){
    // in case if the head is Null
    if(head==NULL){
        node* n = new node(d);
        // pointing head and tail to new node because before this action both was empty
        head = n;
        tail = n;
        return ;
    }
    else{
        // the default case
        node* n = new node(d);
        n->next = head;
        head->prev = n;
        head = n;
    }
}
// insertion on tail side
void ti(node* &tail,node* &head,int d){
    if(tail == NULL){
        node* n = new node(d);
        // pointing head and tail to new node because before this action both was empty
        head = n;
        tail = n;
        return ;
    }
    else{
        node* n = new node(d);
        tail->next = n;
        n->prev = tail;
        tail = n;
    }
}
// insertion on any position

void pi(node* &head,node* &tail,int pstn,int d){
    // if position is one
    if(pstn == 1){
        hi(head,tail,d);
        return ;
    }
    node* temp = head;
    int cnt = 1;
    while(cnt<pstn-1){
        temp = temp->next;
        cnt++;
    }
    // inserting at last positon
    if(temp->next == NULL){
        ti(tail,head,d);
        return ;
    }
    // creating a new node for d
    node* n1 = new node(d);
    n1->next = temp->next;
    temp->next->prev = n1;
    temp->next = n1;
    n1 -> prev = temp;
}

// deleting node
void dn(node* &head,int position){
    // delete first or last element
    if(position == 1){
        node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp ->next = NULL;
        delete temp;
    }
    else{
        // deleting any middle or last element
        node* curr = head;
        node* pre = NULL;
        int cnt = 1;
        // tarverse the linked list
        while(cnt<position){
            pre = curr;
            curr = curr->next;
            cnt++;
        }
        // deleting element
        curr->prev = NULL;
        pre->next = curr->next;
        curr-> next = NULL;
        delete curr;
    }
}
// printing linked list
void pll(node* & head){
    // in case if the head is Null
    if(head == NULL){
        cout<<endl<<"Your Linklist is empty";
        cout<<endl;
    }
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


int main(){
    node* head = NULL;
    node* tail = NULL;
    hi(head,tail,20);
    hi(head,tail,10);
    hi(head,tail,5);
    // ti(tail,head,10);
    // ti(tail,head,20);
    // ti(tail,head,30);
    pi(head,tail,1,2);
    pi(head,tail,2,10);
    pi(head,tail,4,50);
    pi(head,tail,6,500);
    pll(head);
}