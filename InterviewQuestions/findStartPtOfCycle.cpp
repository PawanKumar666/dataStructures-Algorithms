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
head->next->next->next->next->next = head->next;

node* slowPtr = head;
node* fastPtr = head;

while(fastPtr!=NULL){
    fastPtr = fastPtr->next->next;
    slowPtr =slowPtr->next;
    if(fastPtr == slowPtr){
        fastPtr = head;
        while(fastPtr != slowPtr){
            fastPtr = fastPtr->next;
            slowPtr = slowPtr->next;
            break;
        }
        cout<<"The starting point of the cycle is "<<fastPtr->data;
        break;
    }
}
return 0;
}
