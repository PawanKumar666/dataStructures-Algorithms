#include<iostream>

using namespace std;

int Partition(int *A,int start,int stop){

int partitionIndex = start;
int pivot = A[stop];
for(int i = start;i<stop;i++){
    if(A[i]<=A[stop]){
        swap(A[i],A[partitionIndex]);
        partitionIndex = partitionIndex+1;
    }
}
swap(A[stop],A[partitionIndex]);
return partitionIndex;
}

void QuickSort(int *A,int start,int stop){

if(start<stop){
    int partitionIndex = Partition(A,start,stop);
    QuickSort(A,start,partitionIndex-1);
    QuickSort(A,partitionIndex+1,stop);
}
}

int main(){

int A[] = {3,6,4,8,5,0,2,9,1,7};
QuickSort(A,0,(sizeof(A)/sizeof(A[0])));

for(auto& it:A)
    cout<<it<<" ";
return 0;
}
