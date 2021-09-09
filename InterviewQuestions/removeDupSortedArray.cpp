#include<iostream>
#include<vector>

using namespace std;

int main(){

vector<int>sortedVector{1,1,1,2,2,2,2,3,3};

int i = 0;
int j = 1;
while(i<j && j<sortedVector.size()-1){
    if(sortedVector[i] != sortedVector[j]){
        i++;
        sortedVector[i]=sortedVector[j];
    }
    else
        j++;
}
cout<<"The number of different elements are "<<i+1<<endl;

for(int i:sortedVector)
    cout<<i<<" ";
return 0;
}
