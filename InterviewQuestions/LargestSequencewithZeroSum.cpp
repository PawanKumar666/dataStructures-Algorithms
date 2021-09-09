#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main(){

vector<int>myVector{1,-1,3,2,-2,-8,1,7,10,23};

unordered_map<int,int>hashmap;

int sum = 0;
int maxi = 0;

for(int i = 0;i<myVector.size();i++){

    sum+=myVector[i];
    if(sum==0)
        maxi = i+1;

    else{
        if(hashmap.find(sum)!=hashmap.end())
            maxi = max(maxi,i-hashmap[sum]);
        else
            hashmap[sum] = i;

    }
}
cout<<maxi;
return 0;
}
