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

if(head->data > head1->data){
    node* temp = head1;
    head1 = head;
    head = temp;
}
node* temp = head;
node* hold = NULL;
while(head!=NULL && head1!=NULL){
    while(head!=NULL && head->data <= head1->data){
            hold = head;
            head = head->next;
        }
    hold->next = head1;
    node* temporary = head1;
    head1 = head;
    head = temporary;
}

while(temp!=NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
}
return 0;
}
