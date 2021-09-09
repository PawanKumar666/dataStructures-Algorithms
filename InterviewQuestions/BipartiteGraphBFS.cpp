#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool colorUsingBFS(int vertex,vector<int> adjList[],vector<int>& color,queue<int>& q){

q.push(vertex);
color[vertex] = 1;
while(!q.empty()){
    int node = q.front();
    q.pop();
    for(int it : adjList[node]){
        if(color[it] == -1){
            color[it] = 1-color[node];
            q.push(it);
        }
        else{
            if(color[it] == color[node]) return false;
        }
    }
}
return true;
}

int main(){

int nodes = 7;

vector<int> adjList[nodes+1];

adjList[1] = {2};
adjList[2] = {3,7};
adjList[3] = {2,4};
adjList[4] = {3,5};
adjList[5] = {4,6,7};
adjList[6] = {5,7};
adjList[7] = {2,5};

vector<int>color(nodes+1,-1);
queue<int>q;
for(int i=1;i<=7;i++)
    if(color[i] == -1){
        if(!colorUsingBFS(i,adjList,color,q)){
                cout<<"The graph is not a bipartite graph";
                return 0;
        }
    }
    cout<<"The graph is bipartite";
    return 0;
}
