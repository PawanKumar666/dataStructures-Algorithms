#include<iostream>
#include<vector>

using namespace std;

int main(){

vector<vector<int>>matrix{{10,20,30,40},{11,21,36,42},{25,29,39,50},{50,60,70,80}};

int i = 0;
int j = matrix[0].size()-1;
int searchElement;
cin>>searchElement;

while(i<matrix.size() && j>=0){
    if(matrix[i][j] == searchElement){
        cout<<"found at "<< i<< " "<<j;
        break;
    }
    if(matrix[i][j]<searchElement)
        i++;
    else
        j--;
}
return 0;
}
