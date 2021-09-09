#include<iostream>

using namespace std;

int merger(int a[],int temp[],int left,int mid,int right){
int i = left;
int j = mid;
int k = left;
int inv_count = 0;
while((i<=mid-1) && (j<=right)){
    if(a[i] <= a[j])
        temp[k++] = a[i++];
    else{
        temp[k++] = a[j++];
        inv_count=inv_count+ (mid-i);
    }
}
while(i<=mid-1)
    temp[k++] = a[i++];
while(j<=right)
    temp[k++] = a[j++];
for (i = left; i <= right; i++)
        a[i] = temp[i];
return inv_count;
}

int mergeSort(int a[],int temp[],int left,int right){

int inv_count=0;
int mid = 0;
if(right>left){
    mid = (right+left)/2;
    inv_count+=mergeSort(a,temp,left,mid);
    inv_count+=mergeSort(a,temp,mid+1,right);
    inv_count+=merger(a,temp,left,mid+1,right);
}
return inv_count;
}

int main(){

int a[4] = {8,4,2,1};
int temp[4] = {8,4,2,1};
int invCount = mergeSort(a,temp,0,4);
cout<<invCount<<endl;
return 0;
}
