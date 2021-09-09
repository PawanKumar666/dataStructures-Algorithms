#include<bits/stdc++.h>

using namespace std;


void revDfs(int vertex,vector<int> revAdjList[],vector<int>& visited){

cout<<vertex<< " ";
visited[vertex] = 1;

for(int i : revAdjList[vertex]){
    if(!visited[i])
        revDfs(i,revAdjList,visited);
}
}

void dfs(int vertex, stack<int>& topoStack,vector<int> adjList[],vector<int>& visited){

visited[vertex] = 1;

for(int i : adjList[vertex]){
    if(!visited[i])
        dfs(i,topoStack,adjList,visited);
}
topoStack.push(vertex);
}

int main(){

int vertices, edges;
cout<<"Enter number of vertices and edges"<<endl;
cin>>vertices>>edges;

vector<int>adjList[vertices];

for(int i=0;i<edges;i++){
    int u,v;
    cout<<"Enter the edge endpoints"<<endl;
    cin>>u>>v;
    adjList[u].push_back(v);
}

// TopoSort

stack<int> topoStack;
vector<int> visited(vertices,0);

for(int i=0;i<vertices;i++){
    if(!visited[i])
        dfs(i,topoStack,adjList,visited);
}

// Reversing the edges

vector<int> revAdjList[vertices];

for(int i = 0;i<vertices;i++){
    visited[i] = 0;
    for(int j:adjList[i])
        revAdjList[j].push_back(i);
}

// Performing dfs on reversed adjList

while(!topoStack.empty()){
    int top = topoStack.top();
    topoStack.pop();
    if(!visited[top]){
        revDfs(top,revAdjList,visited);
        cout<<endl;
    }
}

return 0;
}
