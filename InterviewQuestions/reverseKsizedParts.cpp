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

int k = 2;

node* traverser = head;
int count = 0;

while(traverser!=NULL){
    count++;
    traverser = traverser->next;
}
node* dummy = new node();
dummy->next = head;
node* prev = dummy;
node* current = dummy;
node* next = dummy;

while(count>=k){
    current = prev->next;
    next = current->next;
    for(int i = 1 ;i<k;i++){
        current->next = next->next;
        next->next = prev->next;
        prev->next = next;
        next = current->next;
    }
    count-=k;
    prev = current;
}
head = dummy->next;
while(head!=NULL){
    cout<<head->data<<" ";
    head = head->next;
}
return 0;
}
