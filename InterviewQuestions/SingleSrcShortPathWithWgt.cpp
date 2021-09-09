#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void topologicalDFS(int index,vector<pair<int,int>>adjList[],vector<int>& visited,stack<int>& topoStack){

visited[index] = 1;
for(auto i: adjList[index]){
    if(!visited[i.first])
        topologicalDFS(i.first,adjList,visited,topoStack);
}
topoStack.push(index);
}

int main(){

vector<pair<int,int>> adjList[6];

adjList[0] = {{1,2},{4,1}};
adjList[1] = {{2,3}};
adjList[2] = {{3,6}};
adjList[3] = {};
adjList[4] = {{2,2},{5,4}};
adjList[5] = {{3,1}};

vector<int> visited(6,0);
vector<int> distance(6,INT_MAX);
stack<int> topoStack;
for(int i = 0;i<6;i++){
    if(!visited[i])
        topologicalDFS(i,adjList,visited,topoStack);
}
distance[0] = 0;
while(!topoStack.empty()){
    int node = topoStack.top();
    topoStack.pop();
    if(distance[node] != INT_MAX){
    for(auto it : adjList[node]){
        if(distance[node]+it.second < distance[it.first])
            distance[it.first] = distance[node]+it.second;
    }
    }
}
for(int i : distance)
    cout<<i<<" ";
return 0;
}
