#include<iostream>
#include<vector>

using namespace std;

int main(){
int n;
cout<<"Enter no. of rows"<<endl;
cin>>n;

vector<vector<int>>pascalVector(n);
for(int i = 0 ;i<n;i++){
    pascalVector[i].resize(i+1);
    pascalVector[i][0] = pascalVector[i][i] = 1;
    for(int j = 1;j<i;j++)
        pascalVector[i][j] = pascalVector[i-1][j-1]+pascalVector[i-1][j];

}
for(int i  = 0;i<n;i++){
    for(int j = 0;j<pascalVector[i].size();j++)
        cout<<pascalVector[i][j]<<" ";
    cout<<endl;
}
return 0;
}
