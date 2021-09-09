//Minimum Spanning tree

#include<iostream>
#include<vector>

using namespace std;

int selectMinVertex(vector<int> value,vector<bool> visited){

int temp = INT_MAX;
int index;
for(int i = 0;i<6;i++){

    if(!visited[i] && value[i]<temp){
        temp = value[i];
        index = i;
    }
}
return index;
}

void primMST(int graphArray[6][6]){

int parent[6];
vector<int>value(6,INT_MAX);
vector<bool>visited(6,false);

value[0] = 0;
parent[0] = 0;

for(int i=0;i<5;i++){
    int selectedVertex = selectMinVertex(value,visited);
    visited[selectedVertex] = true;
    for(int j = 0;j<6;j++){
        if(graphArray[selectedVertex][j]!=0 && !visited[j] && value[j]>graphArray[selectedVertex][j]){
            value[j] = graphArray[selectedVertex][j];
            parent[j] = selectedVertex;
        }
    }
}

for(int i = 0;i<6;i++)
    cout<<"The vertex "<<i<<" with "<<parent[i]<<" as parent "<<" has edge weight of "<<graphArray[parent[i]][i]<<endl;
}

int main(){

int graphArray[6][6] = {{0,4,6,0,0,0},{4,0,6,3,4,0},{6,6,0,1,8,0},{0,3,1,0,2,3},{0,4,8,2,0,7},{0,0,0,3,7,0}};

primMST(graphArray);
}
