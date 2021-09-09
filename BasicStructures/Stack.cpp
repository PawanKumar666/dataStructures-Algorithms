#include<iostream>

using namespace std;

struct node{
int data;
node *next;
};

node* head = NULL;

void Push(int element){
    node* temp = new node();
    temp->data = element;
    temp->next = NULL;
    if(head == NULL){
            head = temp;
            return;
    }
    temp->next = head;
    head = temp;
}

void Pop(){
    head = head->next;
}

void Peep(){
    cout<<"The top element in stack is "<<head->data<<"\n";
}

void Print(){
cout<<"The stack is : ";
node* traverse = head;
while(traverse!=NULL){
    cout<<traverse->data<<" ";
    traverse = traverse->next;
}
cout<<"\n";
}

int main(){

int op=0;
while(op!=4){
cout<<"Enter 1 to insert 2 to pop 3 to print top 4 to exit \n";
cin>>op;
switch(op){

case 1:int element;
cout<<"Enter the number to insert";
cin>>element;
Push(element);
Print();
break;

case 2:Pop();
Print();
break;

case 3:Peep();
Print();
break;

default:cout<<"Enter valid input";

}
}
}
