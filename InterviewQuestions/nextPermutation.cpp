#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

vector<int>myVector = {1,3,4,5,2};
int ind1 = myVector.size()-2;
int ind2 = myVector.size()-1;
while(myVector[ind1]>myVector[ind1+1])ind1--;
while(myVector[ind2]<=myVector[ind1])ind2--;
swap(myVector[ind1],myVector[ind2]);
reverse(myVector.begin()+ind1+1,myVector.end());
for(auto&it : myVector)
    cout<<it<<" ";
return 0;
}
