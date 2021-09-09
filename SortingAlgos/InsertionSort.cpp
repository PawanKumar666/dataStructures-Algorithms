#include<iostream>
#include<vector>

using namespace std;

int main(){

vector<int>myVector = {7,4,8,5,9,3,1,6,2,0};

int space;
int temp;

for(int i=1;i<myVector.size();i++){
    temp = myVector[i];
    space = i;
    while(space>0 && myVector[space-1]>temp){
        myVector[space] = myVector[space-1];
        space = space-1;
    }
    myVector[space] = temp;
}
for(auto& it:myVector)
    cout<<it<<" ";
return 0;
}

