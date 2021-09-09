#include<iostream>

struct node{
int data;
node* next;
node* bottom;
};

using namespace std;

node* merger(node* refer,node* refer1){

node* res = new node();
node* dummy = res;
while(refer!=NULL && refer1!=NULL){
    if(refer->data <= refer1->data){
        res->bottom = refer;
        refer = refer->bottom;
    }
    if(refer1->data <= refer->data){
        res->bottom = refer1;
        refer1 = refer1->bottom;
    }
    res = res->bottom;
}
if(refer)res->bottom = refer;
else res->bottom = refer1;

return res->bottom;
}

node* flatten(node* head){


if(head ==NULL || head->next == nullptr)
    return head;
head->next = flatten(head->next);
head = merger(head,head->next);
return head;
}

int main(){

node* head = new node();

head->data = 1;
head->bottom=new node();
head->bottom->data = 2;
head->bottom->next = NULL;
head->bottom->bottom = NULL;

head->next = new node();

head->next->data = 3;
head->next->bottom=new node();
head->next->bottom->data = 4;
head->next->bottom->next = NULL;
head->next->bottom->bottom = NULL;

head->next->next = new node();

head->next->next->data = 5;
head->next->next->bottom=new node();
head->next->next->bottom->data = 6;
head->next->next->bottom->next = NULL;
head->next->next->bottom->bottom = NULL;

head->next->next->next = new node();

head->next->next->next->data = 7;
head->next->next->next->bottom=new node();
head->next->next->next->bottom->data = 8;
head->next->next->next->bottom->next = NULL;
head->next->next->next->bottom->bottom = NULL;

head->next->next->next->next = new node();

head->next->next->next->next->data = 9;
head->next->next->next->next->bottom=new node();
head->next->next->next->next->bottom->data = 10;
head->next->next->next->next->bottom->next = NULL;
head->next->next->next->next->bottom->bottom = NULL;

head->next->next->next->next->next = NULL;

head = flatten(head);

while(head!=NULL){
    cout<<head->data<<" ";
    head=head->bottom;
}
return 0;
}
