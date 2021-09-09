#include<bits/stdc++.h>

using namespace std;

int main(){

vector<pair<int,int>> adjList[6];

adjList[1] = {{2,2},{4,1}};
adjList[2] = {{1,2},{3,4},{5,5}};
adjList[3] = {{2,4},{4,3},{5,1}};
adjList[4] = {{1,1},{3,3}};
adjList[5] = {{2,5},{3,1}};

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

vector<int> distance(6,INT_MAX);

distance[1] = 0; //1 is source

pq.push(make_pair(1,0));

while(!pq.empty()){
    int node = pq.top().first;
    int dist = pq.top().second;
    pq.pop();
    for(auto it : adjList[node]){
        if(dist+it.second < distance[it.first]){
            distance[it.first] = dist + it.second;
            pq.push(make_pair(it.first,dist+it.second));
        }
    }
}

for(int i=1;i<6;i++)
    cout<<distance[i]<<" ";
return 0;
}
