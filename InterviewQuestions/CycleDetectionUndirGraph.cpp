#include<iostream>
#include<vector>
#include<queue>

using namespace std;

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

// BFS

vector<int>visited(nodes+1,0);
queue<pair<int,int>>q;
int parent = -1;

for(int i=1;i<=7;i++){
    if(!visited[i]){
        visited[i] = 1;
        q.push({i,parent});
        while(!q.empty()){
            pair<int,int> paird = q.front();
            int node = paird.first;
            q.pop();
            for(int it:adjList[node]){
                if(!visited[it]){
                    visited[it] = 1;
                    q.push({it,node});
                }
                else{
                    if(paird.second != it){
                        cout<<"There is a cycle in this graph";
                        return 0;
                }
            }
        }
    }
}
}

return 0;
}
