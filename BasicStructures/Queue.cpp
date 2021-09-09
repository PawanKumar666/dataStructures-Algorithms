#include<iostream>

using namespace std;

struct node{
int data;
node* next;
};

node* Front = NULL;
node* Rear = NULL;

node* Enqueue(int data){

node* newNode = new node();
newNode->data = data;
newNode->next = NULL;

if(Front == NULL){
        Front = newNode;
        Rear = newNode;
        return Front;
}
Rear->next = newNode;
Rear = Rear->next;
return Front;
}

node* Dequeue(){

if(Front == NULL){
    cout<<"Queue is empty"<<endl;
    return Front;
}
if(Front == Rear){
    Front = Rear=  NULL;
    return Front;
}
Front = Front->next;
return Front;
}

void Print(){

node* traverser = Front;
if(Front == NULL){
    cout<<"Queue is empty"<<endl;
    return;
}
while(traverser != NULL){
    cout<<traverser->data<<" ";
    traverser = traverser->next;
}
}

int main(){

int op = 0;

while(op != -1){

    cout<<"1 : Enqueue 2: Dequeue -1 : Exit"<<endl;
    cin>>op;
    switch(op){

    case 1 : int data;
    cout<<"Enter the data to enqueue"<<endl;
    cin>>data;
    Front = Enqueue(data);
    Print();
    cout<<endl;
    break;

    case 2 : Front = Dequeue();
    Print();
    cout<<endl;
    break;

    case -1: cout<<"Exiting the loop"<<endl;
    break;

    default:cout<<"Enter valid option"<<endl;
    }
}
return 0;
}
