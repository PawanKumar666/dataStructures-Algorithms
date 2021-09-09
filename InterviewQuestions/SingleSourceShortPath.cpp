#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){

vector<int> adjList[9];

int src;
cout<<"Enter the source node"<<endl;

adjList[0] = {1,3};
adjList[1] = {0,2,3};
adjList[2] = {1,6};
adjList[3] = {0,1,4};
adjList[4] = {3,5};
adjList[5] = {4,6};
adjList[6] = {2,5,7,8};
adjList[7] = {6,8};
adjList[8] = {6,7};

queue<int> q;
vector<int> distanceVector(9,INT_MAX);
q.push(src);
distanceVector[src] = 0;

while(!q.empty()){
    int node = q.front();
    q.pop();
    for(int it : adjList[node]){
        if(distanceVector[node]+1<distanceVector[it]){
            distanceVector[it] = distanceVector[node]+1;
            q.push(it);
        }
    }
}
for(int dist : distanceVector)
    cout<<dist<<" ";
return 0;
}
