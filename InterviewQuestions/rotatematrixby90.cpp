#include<iostream>
#include<vector>
#include<algorithm>
#define n 3
using namespace std;

int main(){
int element;
vector<vector<int>>matrix{{1,2,3},{4,5,6},{7,8,9}};

for(int i = 0;i<n;i++){
    for(int j = 0;j<i;j++)
        swap(matrix[i][j],matrix[j][i]);
}
for(int i = 0;i<n;i++){
    reverse(matrix[i].begin(),matrix[i].end());
}
for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++)
        cout<<matrix[i][j]<<" ";
    cout<<endl;
}
return 0;
}
