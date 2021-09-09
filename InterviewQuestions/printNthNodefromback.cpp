#include<iostream>

struct node{
int data;
struct node* next;
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

int n;
cout<<"Enter the position from last to fetch"<<endl;
cin>>n;

node* fastptr = head;
node* slowptr = head;

while(fastptr!=NULL){
    if(n){
        fastptr = fastptr->next;
        n--;
    }
    else{
        fastptr = fastptr->next;
        slowptr = slowptr->next;
    }
}
cout<<slowptr->data;
return 0;
}
