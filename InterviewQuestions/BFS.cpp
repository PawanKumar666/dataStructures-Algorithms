#include<iostream>
#include<vector>
#include<queue>

using namespace std;

/*int main(){

int edges;
int endpoint;
vector<pair<int,vector<int>>>graphVector;
for(int i = 0;i<4;i++){
    vector<int>temp;
    cout<<"Enter number of edges of vertex "<<i<<endl;
    cin>>edges;
    for(int j=0;j<edges;j++){
    cout<<"Enter endpoint"<<endl;
    cin>>endpoint;
    temp.push_back(endpoint);
    }
    graphVector.push_back({i,temp});
}
vector<bool>visited(4,false);
queue<int>BFSQueue;
BFSQueue.push(graphVector[0].first);
visited[0] = true;
vector<int>::iterator i;
while(!BFSQueue.empty()){
    endpoint = BFSQueue.front();
    cout<<endpoint<<" ";
    BFSQueue.pop();
    for(i = graphVector[endpoint].second.begin();i!=graphVector[endpoint].second.end();i++){
        if(!visited[graphVector[*i].first])
            BFSQueue.push(graphVector[*i].first);
            visited[graphVector[*i].first] = true;
    }
}
}*/


//Method 2

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

vector<int>visited(nodes+1,0);
queue<int>q;
vector<int> bfsResult;

for(int i = 1;i<=nodes;i++){
    if(!visited[i]){
        q.push(i);
        visited[i] = 1;
        while(!q.empty()){
            int holder = q.front();
            q.pop();
            bfsResult.push_back(holder);
            for(int it : adjList[holder]){
                if(!visited[it]){
                    q.push(it);
                    visited[it] =1;
                }
            }
        }
    }
}
for(int i : bfsResult)
    cout<<i<<" ";

    return 0;
}
