#include<bits/stdc++.h>

using namespace std;

int main(){


vector<pair<int,int>> adjList[5];

adjList[0] = {{1,2},{3,6}};
adjList[1] = {{0,2},{2,3},{3,8},{4,5}};
adjList[2] = {{1,3},{4,7}};
adjList[3] = {{0,6},{1,8}};
adjList[4] = {{1,5},{2,7}};

vector<int> distance(5,INT_MAX);
vector<int> parent{5,-1};
vector<bool> mstSet(5, false);
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

distance[0] = 0;
parent[0] = 0;
pq.push({0,0});

while(!pq.empty()){
    int minNode = pq.top().second;
    pq.pop();
    mstSet[minNode] = true;

    for(auto& it : adjList[minNode]){

        if(mstSet[it.first] == false && distance[it.first]>it.second){
            parent[it.first] = minNode;
            distance[it.first] = it.second;
            pq.push({distance[it.first],it.first});
        }
    }
}

for(int i : parent)
    cout<<i<<" ";

cout<<endl;

for(int i : distance)
    cout<<i<<" ";

return 0;
}
