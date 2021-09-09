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

node* head1 = new node();

head1->data = 2;
head1->next = new node();

head1->next->data = 4;
head1->next->next = new node();

head1->next->next->data = 6;
head1->next->next->next = new node();

head1->next->next->next->data = 8;
head1->next->next->next->next = new node();

head1->next->next->next->next->data = 10;
head1->next->next->next->next->next = NULL;

node* refer = new node();
node* temp = refer;
int carry = 0;
while(head!=NULL || head1!=NULL || carry){
    int sum = 0;
    if(head!=NULL){
        sum+=head->data;
        head = head->next;
    }
    if(head1!=NULL){
        sum+=head1->data;
        head1 = head1->next;
    }
    sum+=carry;
    carry = sum/10;
    node* attach = new node();
    attach->data = sum%10;
    temp->next = attach;
    temp = temp->next;
}

refer= refer->next;

node* prev = NULL;
node* current = refer;
node* temp1;

while(current!=NULL){
    temp1 = current->next;
    current->next = prev;
    prev = current;
    current = temp1;
}

while(prev!=NULL){
    cout<<prev->data<<" ";
    prev = prev->next;
}
return 0;
}
