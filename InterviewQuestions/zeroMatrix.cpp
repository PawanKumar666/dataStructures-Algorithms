#include<iostream>
#include<vector>

using namespace std;

int main(){

int a[5][5] = {{1,1,1,1,1},{1,1,1,1,1},{1,1,0,1,1},{1,0,1,1,1},{0,1,1,1,1}};

for(int i = 0;i<5;i++){
    for(int j = 0;j<5;j++){
        if(a[i][j] == 0)
            for(int k = 0;k<5;k++){
                a[i][k] = -1;
                a[k][j] = -1;
            }
    }
}
for(int i = 0;i<5;i++){
    for(int j = 0;j<5;j++){
        if(a[i][j] == -1)
            cout<<0<<" ";
        else
            cout<<a[i][j]<<" ";
    }
    cout<<endl;
}
return 0;
}
