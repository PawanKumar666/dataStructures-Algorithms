#include<iostream>

using namespace std;

#define MAX_SIZE 10

int main(){

int a[MAX_SIZE];
for(int i=0;i<MAX_SIZE;i++)
    cin>>a[i];
int maxi = a[0];
int mini = a[0];
for(int i=1;i<MAX_SIZE;i++){
        if(a[i]>maxi)
            maxi = a[i];
        if(a[i]<mini)
            mini = a[i];
}
cout<<"Maximum element is : "<<maxi<<" Minimum element is : "<<mini;
return 0;
}
