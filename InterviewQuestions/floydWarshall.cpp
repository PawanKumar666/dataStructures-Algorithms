//All pair shortest path

#include<iostream>
#include<vector>
#define v 6

using namespace std;

void floyd_warshall(int graph[v][v]){

for(int k = 0;k<v;k++){
    for(int i = 0;i<v;i++){
        for(int j = 0;j<v;j++){
            if(graph[i][k] == INT_MAX || graph[k][j] == INT_MAX)
                continue;
            else{
                if(graph[i][k]+graph[k][j] < graph[i][j])
                    graph[i][j] = graph[i][k]+graph[k][j];
        }
    }
}
}
for(int i=0;i<v;++i)
		if(graph[i][i] < 0)
		{
			cout<<"Negative edge weight cycle is present\n";
			return;
		}
	for(int i=1;i<v;++i)
	{
		for(int j=0;j<v;++j)
			cout<<i<<" to "<<j<<" distance is "<<graph[i][j]<<"\n";
		cout<<"=================================\n";
	}
}

int main(){

int graph[v][v] = { {0, 1, 4, INT_MAX, INT_MAX, INT_MAX},
                    {INT_MAX, 0, 4, 2, 7, INT_MAX},
                    {INT_MAX, INT_MAX, 0, 3, 4, INT_MAX},
                    {INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 4},
                    {INT_MAX, INT_MAX, INT_MAX, 3, 0, INT_MAX},
                    {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 5, 0} };

floyd_warshall(graph);
return 0;
}
