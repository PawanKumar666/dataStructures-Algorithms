#include<iostream>
#include<vector>
using namespace std;

int main(){

vector<int> myVector = {3,6,9,5,2,4,7,1,8};

int indMin;
int temp;

for(int i = 0;i<myVector.size()-1;i++){
    indMin = i;
    for(int j = i+1;j<myVector.size();j++){
        if(myVector[j]<myVector[indMin])
            indMin = j;
    }
    temp = myVector[i];
    myVector[i] = myVector[indMin];
    myVector[indMin] = temp;
}
for(auto& it:myVector)
    cout<<it<<" ";
return 0;
}
