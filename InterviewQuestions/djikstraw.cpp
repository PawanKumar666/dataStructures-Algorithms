//Single Source Shortest path

#include<iostream>
#include<vector>

using namespace std;

//Print graph
void printGraph(vector<vector<pair<int,int>>> graphVector){
for(int i = 0;i<6;i++){
    for(int j = 0;j<graphVector[i].size();j++){
        cout<<"Vertex "<<i<<" forming edge with vertex "<<graphVector[i][j].first<<" has "<<graphVector[i][j].second<<" weight"<<endl;
    }
}
}
int selectMinVertex(vector<int> value,vector<int> visited){

int minIndex = 0;
int temp = INT_MAX;
for(int i = 0;i<value.size();i++){
    if(!visited[i] && value[i]<temp){
        temp = value[i];
        minIndex = i;
    }
}
return minIndex;
}

void djikstraw(int graphVector[6][6]){

vector<int>visited(6,0);
vector<int>parent(6,-1);
vector<int>value(6,INT_MAX);
int selectedVertex;

value[0] = 0;

for(int i = 0;i<5;i++){
    selectedVertex = selectMinVertex(value,visited);
    visited[selectedVertex] = 1;
    for(int j = 0;j<6;j++){
        if(graphVector[selectedVertex][j]!=0 && !visited[j] && value[selectedVertex]+graphVector[selectedVertex][j] < value[j]){
            value[j] = value[selectedVertex]+graphVector[selectedVertex][j];
            parent[j] = selectedVertex;
        }
    }
}

for(auto& it:parent)
    cout<<it<<" ";
cout<<endl;

for(auto& it:value)
    cout<<it<<" ";
}

int main(){



/*  vector<vector<pair<int,int>>> graphVector;
    for(int i=0;i<6;i++){
    vector<pair<int,int>> tempVector;
    cout<<"Enter number of edges"<<endl;
    cin>>edges;
    for(int j = 0;j<edges;j++){
        cout<<"Enter endpoint vertex"<<endl;
        cin>>endpoint;
        cout<<"Enter edge weight"<<endl;
        cin>>weight;
        tempVector.push_back(make_pair(endpoint,weight));
    }
    graphVector.push_back(tempVector);
}
printGraph(graphVector);*/
int graphVector[6][6] = {{0,1,4,0,0,0},{1,0,4,2,7,0},{4,4,0,3,5,0},{0,2,3,0,4,6},{0,7,5,4,0,7},{0,0,0,6,7,0}};
djikstraw(graphVector);
return 0;
}

