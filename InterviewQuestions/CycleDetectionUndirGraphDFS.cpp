#include<iostream>
#include<vector>

using namespace std;

bool dfs(int vertex,int parent,vector<int>& visited, vector<int> adjList[]){

visited[vertex] = 1;

for(int it : adjList[vertex]){
    if(!visited[it])
        if(dfs(it,vertex,visited,adjList)) return true;
    else{
        if(parent != it) return true;
    }
}
return false;
}

int main(){

int nodes = 7;

vector<int> adjList[nodes+1];

adjList[1] = {2};
adjList[2] = {3,7};
adjList[3] = {2,5};
adjList[4] = {6};
adjList[5] = {3,7};
adjList[6] = {4};
adjList[7] = {2,5};

vector<int>visited(nodes+1,0);

for(int i = 1;i<=7;i++){
    if(!visited[i])
        if(dfs(i,-1,visited,adjList)) cout<<"There is a cycle";
}
return 0;
}
