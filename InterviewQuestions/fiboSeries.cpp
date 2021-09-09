#include<bits/stdc++.h>

using namespace std;

int fibo(int n,vector<int>& dp){

if(dp[n]) return dp[n];
else if(n == 0) return 0;
dp[n] = fibo(n-2,dp) + fibo(n-1,dp);
}
int main(){

int n;
cout<<"Enter the number of elements to print on fibonacci series";
cin>>n;
vector<int> dp(n,0);
dp[0] = 0;
dp[1] = 1;
fibo(n,dp);
for(int i : dp)
    cout<<i<< " ";
return 0;
}
