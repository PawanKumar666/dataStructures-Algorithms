#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void topologicalSortDFS(int index,vector<int>& visited, vector<int> adjList[],stack<int>& resultStack){

visited[index] = 1;

for(int i : adjList[index]){
    if(!visited[i])
        topologicalSortDFS(i,visited,adjList,resultStack);
}
resultStack.push(index);
}

int main(){

int nodes = 9;

vector<int> adjList[10];
stack<int> resultStack;

adjList[1] = {2};
adjList[2] = {3};
adjList[3] = {4,6};
adjList[4] = {5};
adjList[5] = {};
adjList[6] = {5};
adjList[7] = {2,8};
adjList[8] = {9};
adjList[9] =  {7};


vector<int>visited(nodes+1,0);

for(int i = 1;i<=9;i++){
    if(!visited[i])
        topologicalSortDFS(i,visited,adjList,resultStack);
}
vector<int> result;
while(!resultStack.empty()){
    result.push_back(resultStack.top());
    resultStack.pop();
}
for(int it : result)
    cout<<it<<" ";
return 0;
}
