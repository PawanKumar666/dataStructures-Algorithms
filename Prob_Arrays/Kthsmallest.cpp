#include<iostream>
#define MAX_SIZE 10

using namespace std;

int main(){

int a[MAX_SIZE];
int temp = 0;
cout<<"Give the array elements"<<endl;
for(int i=0;i<MAX_SIZE;i++)
    cin>>a[i];
int k;
cout<<"Enter the kth smallest element you want to find"<<endl;
cin>>k;
if(k>=MAX_SIZE){
    cout<<"Invalid position";
    return 0;
}
for(int i=0;i<k;i++){
    for(int j = i+1;j<MAX_SIZE;j++){
        if(a[i]>a[j]){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
}
for(int i=0;i<MAX_SIZE;i++)
    cout<<a[i]<<" ";
cout<<"The "<<k<<"'th smallest element in the array is "<<a[k-1]<<endl;
return 0;
}
