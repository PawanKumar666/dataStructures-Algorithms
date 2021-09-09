#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main(){

vector<int> myVector{3,3,3,1,1,2,2,2};
int n = myVector.size()/3;
unordered_map<int,int>hashMap;

for(int num:myVector)
    hashMap[num]++;

for(auto& it:hashMap){
    if(it.second > n)cout<<it.first<<" ";
}
return 0;
}
