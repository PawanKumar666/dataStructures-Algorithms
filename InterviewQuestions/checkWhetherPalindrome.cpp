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

head->next->next->next->data = 3;
head->next->next->next->next = new node();

head->next->next->next->next->data = 1;
head->next->next->next->next->next = NULL;

int flag = 0;

node* slow = head;
node* fastPtr = head;

while(fastPtr->next!=NULL && fastPtr->next->next!=NULL){
    slow = slow->next;
    fastPtr = fastPtr->next->next;
}
node* current = slow->next;
node* prev = NULL;
node* temp;

while(current!=NULL){
    temp = current->next;
    current->next = prev;
    prev = current;
    current = temp;
}
slow->next = prev;
slow = slow->next;

while(slow!=NULL){
    if(slow->data != head->data){
        flag = 1;
        break;
    }
    slow = slow->next;
    head = head->next;
}
if(flag)
    cout<<"It is not a palindrome";
else
    cout<<"It is a palindrome";

return 0;
}
