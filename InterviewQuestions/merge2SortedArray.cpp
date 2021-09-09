#include<iostream>
#include<vector>

using namespace std;

int main(){

int a[5]={1,4,5,7,9};
int b[5]={2,3,6,8,10};
int insertElement;
int k;
for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){
    if(a[i]>b[0]){
        swap(a[i],b[0]);
        insertElement = b[0];
        for(k = 1;k<sizeof(b)/sizeof(b[0]) && b[k] < insertElement;k++)
            b[k-1] = b[k];
        b[k-1] = insertElement;
    }
}
for(auto& it:a)
    cout<<it<<" ";
for(auto& it:b)
    cout<<it<<" ";
return 0;
}
