#include<iostream>
using namespace std;
int main(){

int a[10]={3,1,2,4,5,3,6,7,3,3};

int key,space;
cin>>key>>space;

int counter = space-1;
int i,j;
for(i=0;i<10;i = i+space){
    for(j = 0;j<space;j++){
        if(a[i+j] == key)
            break;
    }
    if (j==space)
        cout<<"Key not present"<<endl;
}

if(i!=10){

    for(j=i-space;j<10;j++){

        if(a[j]==key)
            break;
    }
    if(j == 10)
        cout<<"Key not present"<<endl;
}
return 0;
}
