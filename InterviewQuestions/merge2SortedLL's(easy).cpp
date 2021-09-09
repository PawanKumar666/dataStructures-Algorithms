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

node* result = new node();
result->next = NULL;
node* ans = result;
while(head != NULL && head1!=NULL){
    node* temp = new node();
    if(head->data<=head1->data){
        temp->data = head->data;
        head = head->next;
    }
    if(head->data>head1->data){
        temp->data = head1->data;
        head1 = head1->next;
    }
    result->next = temp;
    result = result->next;
}

while(head1!=NULL){
    result->next = head1;
    head1 = head1->next;
}
while(head!=NULL){
    result->next = head->next;
    head = head->next;
}
ans = ans->next;

while(ans!=NULL){
    cout<<ans->data<<" ";
    ans = ans->next;
}
return 0 ;
}
