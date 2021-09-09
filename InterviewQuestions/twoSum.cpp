#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main(){

vector<int>myVector{2,6,5,8,11};
unordered_map<int,int> hashMap;

int target = 14;

vector<int>result;

for(int i=0;i<myVector.size();i++){
    if(hashMap.find(target-myVector[i]) != hashMap.end()){
        result.push_back(hashMap[target-myVector[i]]);
        result.push_back(i);
    }
    hashMap[myVector[i]] = i;
}
for(int i:result)
    cout<<i<<" ";
return 0;
}
