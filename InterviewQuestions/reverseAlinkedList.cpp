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
head->next->next->next = NULL;

node* prev = NULL;
node* temp = NULL;

while(head!=NULL){
    temp = head->next;
    head->next = prev;
    prev = head;
    head = temp;
}
node* traverser = prev;
while(traverser!=NULL){
    cout<<traverser->data<<" ";
    traverser = traverser->next;
}
return 0;
}
