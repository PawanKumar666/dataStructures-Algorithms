#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int>graphVector[6];
//Create graph
void createGraph(){
int edges;
int endpoint;
for(int i=0;i<6;i++){
    cout<<"Enter number of edges"<<endl;
    cin>>edges;
    for(int j=0;j<edges;j++){
        cout<<"Enter the endpoint of edge"<<endl;
        cin>>endpoint;
        graphVector[i].push_back(endpoint);
    }
}
}
//Print the graph
void printGraph(){
for(int i=0;i<6;i++){
    cout<<"Vertex "<<i<<" : ";
    for(int j=0;j<graphVector[i].size();j++)
            cout<<graphVector[i][j]<<" ";
    cout<<endl;
}
}
void topologicalSortHelper(int v,vector<bool> visited,stack<int>& result){

visited[v] = true;
vector<int>::iterator it;
for(it=graphVector[v].begin();it!=graphVector[v].end();it++){
    if(!visited[*it])
        topologicalSortHelper(*it,visited,result);
}
result.push(v);
}

void topologicalSort(){
vector<bool>visited(6,false);
stack<int>revResult;
cout<<"in fun"<<endl;
for(int i=0;i<6;i++){
        if(!visited[i]){
            topologicalSortHelper(i,visited,revResult);
        }
    }
while(!revResult.empty()){
    cout<<revResult.top()<<" ";
    revResult.pop();
}
}

int main(){
createGraph();
printGraph();
topologicalSort();
}
