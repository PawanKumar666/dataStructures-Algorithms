#include<iostream>
#include<vector>

using namespace std;

bool isCycleDFS(int index,vector<int>& visited,vector<int>& DFSvisited,vector<int> adjList[]){

visited[index] = 1;
DFSvisited[index] = 1;

for(int it : adjList[index]){
    if(!visited[it]){
        if(isCycleDFS(it,visited,DFSvisited,adjList)) return true;
    }
    else{
        if(DFSvisited[it]) return true;
    }
}
DFSvisited[index] = 0;
return false;

}

int main(){

vector<int> visited(9+1,0);
vector<int> DFSvisited(9+1,0);

vector<int> adjList[10];

adjList[1] = {2};
adjList[2] = {3};
adjList[3] = {4,6};
adjList[4] = {5};
adjList[5] = {};
adjList[6] = {5};
adjList[7] = {2,8};
adjList[8] = {9};
adjList[9] =  {7};

for(int i = 1;i<=9;i++){
    if(!visited[i]){
        if(isCycleDFS(i,visited,DFSvisited,adjList)){
            cout<<"There is a cycle";
            return 0;
        }
    }
}
cout<<"There is no cycle";
return 0;
}
