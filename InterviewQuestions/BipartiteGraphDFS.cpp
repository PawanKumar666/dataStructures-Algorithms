#include<iostream>
#include<vector>

using namespace std;


bool bipartiteDFS(int index,vector<int> adjList[],vector<int>& color){

if(color[index] == -1)color[index] = 1;

for(int it : adjList[index]){
    if(color[it] == -1){
        color[it] = 1-color[index];
        if(!bipartiteDFS(it,adjList,color)) return false;
    }
    else{
        if(color[it] == color[index]) return false;
    }
}
return true;
}

int main(){

int nodes = 7;

vector<int> adjList[nodes+1];

adjList[1] = {2};
adjList[2] = {1,3,5};
adjList[3] = {2,4};
adjList[4] = {3,5};
adjList[5] = {2,4,6};
adjList[6] = {5};

vector<int>color(nodes+1,-1);

for(int i =1;i<=6;i++){
    if(color[i] == -1){
        if(!bipartiteDFS(i,adjList,color)){
                cout<<"The graph is not bipartite";
                return 0;
    }
    }
}
cout<<"The graph is bipartite";
return 0;
}
