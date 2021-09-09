#include<iostream>
#include<vector>

using namespace std;

int main(){

vector<int>block{0,1,0,2,1,0,1,3,2,1,2,1};
int left = 0;
int right = block.size()-1;
int leftMax = 0;
int rightMax = 0;
int trappedWater = 0;

while(left<right){
    if(block[left]<=block[right]){
        if(block[left]>leftMax)
            leftMax = block[left];
        else
            trappedWater += leftMax-block[left];
        left++;
    }
    else{
        if(block[right]>rightMax)
            rightMax = block[right];
        else
            trappedWater += rightMax-block[right];
        right--;
    }
}
cout<<"The total rainwater trapped is "<<trappedWater;
return 0;
}
