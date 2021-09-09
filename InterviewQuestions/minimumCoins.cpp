#include<iostream>

using namespace std;

int main(){

int a[9] = {1,2,5,10,20,50,100,500,1000};

int value = 197;

int i=8;

while(value!=0){
    if((value/a[i]) != 0){
        cout<<(value/a[i])<<" x "<<a[i]<<endl;
        value -= (value/a[i])*a[i];
    }
    i--;
 }
 return 0;
}
