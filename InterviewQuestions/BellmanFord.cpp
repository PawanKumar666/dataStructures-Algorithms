#include<iostream>
#include<vector>

struct edge{
int src,dst,wgt;
};
int v,e;

using namespace std;

void bellmanFord(vector<edge> edges){

int parent[v];
vector<int> value(v,INT_MAX);

parent[0] = -1;
value[0] = 0;
bool updated;
for(int i=0;i<v-1;i++){
    updated = false;
    for(int j = 0;j<e;j++){
        int src = edges[j].src;
        int dst = edges[j].dst;
        int wgt = edges[j].wgt;
        if(value[src]!=INT_MAX && value[src]+wgt < value[dst]){
            value[dst] = value[src]+wgt;
            parent[dst] = src;
            updated = true;
        }
    }
    if(updated == false)
        break;
}
for(int j = 0;j<e;j++){
    int src = edges[j].src;
    int dst = edges[j].dst;
    int wgt = edges[j].wgt;
    if(value[src]!=INT_MAX && value[src]+wgt < value[dst])
            cout<<"There exists a negative edge weight cycle"<<endl;
}
for(int i=0;i<v;++i)
		cout<<"U->V: "<<parent[i]<<"->"<<i<<"  Cost to reach "<<parent[i]<<"from source 0 = "<<value[i]<<"\n";
}

int main(){

cin>>v>>e;
vector<edge>edges(e);
int src;int dst;int wgt;
for(int i=0;i<e;i++){
    cin>>src>>dst>>wgt;
    edges[i].src=src;
    edges[i].dst=dst;
    edges[i].wgt=wgt;
}
bellmanFord(edges);
return 0;
}
