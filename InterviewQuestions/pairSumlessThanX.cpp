#include<iostream>
#include<vector>

using namespace std;

int main(){

vector<int>myVector = {2,4,5 ,8,9};
int x = 14;
int start = 0;
int count = 0;
int stop = myVector.size()-1;
while(start!=stop){
    if(myVector[start]+myVector[stop]<x){
        count += stop-start;
        start += 1;
    }
    else
        stop -= 1;
}

cout<<count<<endl;
}
