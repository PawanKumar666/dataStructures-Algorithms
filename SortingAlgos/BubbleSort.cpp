#include<iostream>
#include<vector>

using namespace std;

int main(){

vector<int> myVector = {3,6,9,5,2,4,7,1,8};

int temp;

for(int i = 0;i<myVector.size()-1;i++){
    for(int j = 0;j<myVector.size()-i-1;j++){
        if(myVector[j]>myVector[j+1]){
            temp = myVector[j];
            myVector[j] = myVector[j+1];
            myVector[j+1] = temp;
        }
    }
}
for(auto& it:myVector)
    cout<<it<<" ";
return 0;
}
