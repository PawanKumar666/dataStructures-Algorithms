#include<iostream>

struct node{
int data;
node* next;
};

using namespace std;

int main(){

node* head = new node();

head->data = 1;
head->next = new node();

head->next->data = 3;
head->next->next = new node();

head->next->next->data = 5;
head->next->next->next = new node();

head->next->next->next->data = 7;
head->next->next->next->next = new node();

head->next->next->next->next->data = 9;
head->next->next->next->next->next = NULL;

int k;
cout<<"Enter how many positions to rotate";
cin>>k;
node* slowPtr = head;
node* fastPtr = head;

node* traverser = head;
int count = 0;
while(traverser!=NULL){
    count++;
    traverser = traverser->next;
}
k=k%count;
while(fastPtr->next!=NULL){
    fastPtr = fastPtr->next;
    if(k-- <=0)
        slowPtr = slowPtr->next;
}
fastPtr->next = head;
head = slowPtr->next;
slowPtr->next = NULL;

while(head!=NULL){
    cout<<head->data<<" ";
    head = head->next;
}
return 0;
}
