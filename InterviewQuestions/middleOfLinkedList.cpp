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

head->next->data = 2;
head->next->next = new node();

head->next->next->data = 3;
head->next->next->next = new node();

head->next->next->next->data = 4;
head->next->next->next->next = new node();

head->next->next->next->next->data = 5;
head->next->next->next->next->next = NULL;

node* fastptr = head;
node* slowptr = head;

while(fastptr->next!=NULL){
    fastptr = fastptr->next->next;
    slowptr = slowptr->next;
}
cout<<slowptr->data;
return 0;
}
