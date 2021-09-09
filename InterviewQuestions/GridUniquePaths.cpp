#include<iostream>
#include<vector>

using namespace std;


int uniquePaths(int i,int j,vector<vector<int>>& dp, int m,int n){

if(i>=m || j>=n)
    return 0;
if(i == m-1 && j == n-1)
    return 1;
if(dp[i][j]!=-1)
    return dp[i][j];

return dp[i][j] = uniquePaths(i+1,j,dp,m,n)+ uniquePaths(i,j+1,dp,m,n);

}
int main(){

vector<vector<int>>dp(3,vector<int>(3,-1));
cout<<uniquePaths(0,0,dp,3,2);
return 0;
}
