#include<iostream>
#include<vector>

using namespace std;

int main(){

vector<vector<int>>matrix{{1,3,5,7},{10,11,16,20},{23,30,34,50}};

int low = 0;
int high = (matrix[0].size()*matrix.size())-1;
int searchElement;
cin>>searchElement;

while(low<=high){
    int mid = (low+high)/2;
    if(matrix[mid/matrix[0].size()][mid%matrix[0].size()] == searchElement){
        cout<<"Found in "<<mid/matrix[0].size()<<" "<<mid%matrix[0].size();
        break;
    }
    if(matrix[mid/matrix[0].size()][mid%matrix[0].size()] < searchElement)
        low = mid+1;
    else
        high = mid-1;
}
return 0;
}
