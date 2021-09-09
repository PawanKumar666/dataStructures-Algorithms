#include<iostream>
#include<stack>

using namespace std;

struct node{

int data;
node* next;
};

stack<struct node*> S;

node *head;

int middleFinder(node* head){

node* slowPtr = head;
node* fastPtr = head;

while(fastPtr->next!=NULL){
    fastPtr = fastPtr->next->next;
    slowPtr = slowPtr->next;
}
return slowPtr->data;
}

node* reverseWithStack(node* head){

node* traverser = head;
while(traverser!=NULL){
    S.push(traverser);
    traverser = traverser->next;
}
traverser = S.top();
head = traverser;
S.pop();

while(!S.empty()){
    traverser->next = S.top();
    S.pop();
    traverser = traverser->next;
}
traverser->next = NULL;
return head;
}

node* reverseLlist(node* head){

node *present = head;
node *past = NULL;
node *future;

while(present != NULL){

    future = present->next;
    present->next = past;
    past = present;
    present = future;

}
return past;
}

void reverseLlistRecursion(node* ptr){

if(ptr->next == NULL){

    head = ptr;
    return;
}
reverseLlistRecursion(ptr->next);
node* temp = ptr->next;
temp->next = ptr;
ptr->next = NULL;
}

node* Insert(int in,int inPos){

node *temp = new node();
temp->data = in;
temp->next = NULL;
if(head == NULL){

    head = temp;
    return head;
}
if(inPos == 1){

    temp->next = head;
    head = temp;
    return head;
}
node *traverser = head;
for(int i=0;i<inPos-2;i++){
    traverser = traverser->next;
}
temp->next = traverser->next;
traverser->next = temp;
return head;
}

node* Delete(int delPos){

node *temp = head;

if(head == NULL){
    cout<<"List is empty";
    return head;
}
if(delPos == 1){
    head = temp->next;
    return head;
}
node *traverser = head;

for(int i = 0;i<delPos-2;i++){
    traverser = traverser->next;
}

traverser->next = traverser->next->next;
return head;

}

void forwardTraverse(){
node* traverser = head;
while(traverser != NULL){
    cout<<traverser->data;
    cout<<" ";
    traverser = traverser->next;
}
cout<<"\n";
}

node* reverseTraverse(node* head){

node* reverseTraverser = head;

if(reverseTraverser == NULL){
    cout<<"\n";
    return head;
}


reverseTraverse(reverseTraverser->next);
cout<<reverseTraverser->data;
cout<<" ";
}

int main(){

head = NULL;
int op=0;

while(op!=-1){
cout<<"1 : Insert 2 : Delete 3 : Print 4 : Reverse \n5 : reverse with recursion 6 : Reverse with stack 7 : Find middle element -1 : Exit\n";
cin>>op;
switch(op){

case 1 : cout<<"Enter the number to insert ";
int in;
cin>>in;
cout<<"Enter the position to insert ";
int inPos;
cin>>inPos;
head = Insert(in,inPos);
forwardTraverse();
break;

case 2 : cout<<"Enter the position to delete ";
int delPos;
cin>>delPos;
head = Delete(delPos);
forwardTraverse();
break;

case 3 : cout<<"1 : Forward traversal 2 :Reverse traversal ";
int travOpt;
cin>>travOpt;
switch(travOpt){
case 1 : forwardTraverse();
break;
case 2 : head = reverseTraverse(head);
break;
default : cout<<"Enter valid input";
}
break;

case 4 : head = reverseLlist(head);
forwardTraverse();
break;

case 5 : reverseLlistRecursion(head);
forwardTraverse();
break;

case 6 : head = reverseWithStack(head);
forwardTraverse();
break;

case 7 : cout<<"The middle element of the linked list is "<<middleFinder(head)<<endl;
break;

default:cout<<"Enter valid input";
}
}
}
