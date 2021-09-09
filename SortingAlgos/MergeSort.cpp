#include<iostream>

using namespace std;

void Merge(int *A,int *L,int *R,int leftSize,int rightSize){

int i,j,k;
i=0;j=0;k=0;

while(i<leftSize && j<rightSize){
    if(L[i]<R[j])A[k++] = L[i++];
    else A[k++] = R[j++];
}
while(i<leftSize)A[k++] = L[i++];
while(j<rightSize)A[k++] = R[j++];

}

void MergeSort(int *A,int len){

int *L,*R,mid;

if(len < 2 )
    return;

mid = len/2;

L = (int*)malloc(sizeof(int)*mid);
R = (int*)malloc(sizeof(int)*(len-mid));

for(int i = 0;i<mid;i++)
    L[i] = A[i];
for(int i = mid;i<len;i++)
    R[i-mid] = A[i];

MergeSort(L,mid);
MergeSort(R,len-mid);
Merge(A,L,R,mid,len-mid);
free(L);
free(R);
}

int main(){

int A[] = {3,6,4,7,5,8,2,9,1,0};

MergeSort(A,(sizeof(A)/sizeof(A[0])));

for(auto& it:A)
    cout<<it<<" ";

return 0;
}

