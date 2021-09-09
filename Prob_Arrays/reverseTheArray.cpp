#include<iostream>
#define MAX_SIZE 10

using namespace std;

int main(){

int a[MAX_SIZE],temp;
for(int i=0;i<MAX_SIZE;i++)
    cin>>a[i];
int start = 0;
int finish = MAX_SIZE-1;

while(start < finish){
    temp = a[start];
    a[start] = a[finish];
    a[finish] = temp;
    start++;
    finish--;
}
for(int i =0;i<MAX_SIZE;i++)
    cout<<a[i]<<" ";
return 0;
}
