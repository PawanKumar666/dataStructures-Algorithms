#include<iostream>
#define MAX_SIZE 3

using namespace std;

int a[MAX_SIZE];
int Front= -1;
int Rear = -1;

void Enqueue(int inElement){

if(Front == -1 && Rear == -1){
    Front = Front+1;
    a[(Rear+1)%MAX_SIZE] = inElement;
    Rear = Rear+1;
    return;
}
if((Rear+1)%MAX_SIZE == Front){
    cout<<"Queue is Full"<<endl;
    return;
}
Rear = (Rear+1)%MAX_SIZE;
a[Rear] = inElement;
return;
}

void Dequeue(){
    if(Front == -1 && Rear == -1){
        cout<<"Queue is empty"<<endl;
        return;
    }
    if(Front == Rear){
        Front = -1;
        Rear = -1;
        return;
    }
    Front = (Front+1)%MAX_SIZE;
    return;
}

int printTop(){
return a[Front];
}

int main(){

int op = 0;
while(op != -1){

cout<<"1 : Enqueue 2 : Dequeue -1 : Exit"<<endl;
cin>>op;
switch(op){

case 1: int inElement;
cout<<"Enter the element to enqueue"<<endl;
cin>>inElement;
Enqueue(inElement);
cout<<"Top is "<<printTop();
cout<<endl;
break;

case 2: Dequeue();
cout<<"Top is "<<printTop();
cout<<endl;
break;

case -1: cout<<"Exiting the loop"<<endl;
break;

default: cout<<"Enter valid input"<<endl;
break;
}
}
return 0;
}
