#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// Method 1 - Adjacency matrix

/*void DFS(int v,vector<bool>& visited,int graphArray[6][6]){

visited[v] = true;
cout<<v<<" ";
for(int i = 0;i<6;i++){
    if(graphArray[v][i]!=0 && !visited[i])
        DFS(i,visited,graphArray);
}
}


int main(){

vector<bool>visited(6,false);
int graphArray[6][6] = {{0,1,1,0,0,0},
                        {1,0,0,1,1,0},
                        {1,0,0,0,1,0},
                        {0,1,0,0,1,1},
                        {0,1,1,1,0,1},
                        {0,0,0,1,1,0}};

DFS(0,visited,graphArray);
return 0;
}*/

//Method 2 - Adjacency List

void dfs(int vertex,vector<int>& visited,vector<int> adjList[]){

visited[vertex] = 1;
cout<<vertex<<" ";

for(int i : adjList[vertex]){
    if(!visited[i])
        dfs(i,visited,adjList);
}
}

int main(){

vector<int>visited(8,0);

vector<int> adjList[8];

adjList[0] = {1,2};
adjList[1] = {0,3,4};
adjList[2] = {0,4};
adjList[3] = {1,4,5};
adjList[4] = {1,2,3,5};
adjList[5] = {3,4};
adjList[6] = {7};
adjList[7] = {6};

for(int i = 0;i<8;i++){
    if(!visited[i])
        dfs(i,visited,adjList);
}
return 0;
}
