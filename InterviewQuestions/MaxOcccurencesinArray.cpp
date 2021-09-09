#include<iostream>
#include<vector>

using namespace std;

int main(){

vector<int> myVector{7,1,7,1,7,1,7,1,7};

//Moore's Voting algorithm

int count = 0;
int candidate;
for(int num:myVector){
    if(count == 0)
        candidate = num;
    if(num == candidate)
        count++;
    else
        count--;
}
cout<<candidate;
return 0;
}
