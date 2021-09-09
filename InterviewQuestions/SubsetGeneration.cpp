#include<iostream>
#include<vector>

using namespace std;

void findSubsets(int index,vector<int>data,vector<vector<int>>& answer,vector<int>& ds){

answer.push_back(ds);

for(int i = index;i<data.size();i++){
    if(i!=index && data[i] == data[i-1])continue;
    ds.push_back(data[i]);
    findSubsets(i+1,data,answer,ds);
    ds.pop_back();
}
}

int main(){

vector<int>data{1,2,2,2,3,3};
vector<vector<int>>answer;
vector<int>ds;

findSubsets(0,data,answer,ds);

for(vector<int> i: answer){
    for(int j : i)
        cout<<j<<" ";
    cout<<endl;
}
return 0;
}
