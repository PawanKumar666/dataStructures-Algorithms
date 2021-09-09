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
head1->next->next->next->next = head->next->next;

node* tempHead = head;
node* tempHead1 = head1;

while(head!=NULL || head1!=NULL){
    if(head!=NULL)
        head=head->next;
    if(head1!=NULL)
        head1 = head1->next;
    if(head == NULL)
        head = tempHead1;
    if(head1 == NULL)
        head1 = tempHead;
    if(head == head1){
        cout<<"Intersection point is "<<head->data;
        break;
    }
}
return 0;
}
