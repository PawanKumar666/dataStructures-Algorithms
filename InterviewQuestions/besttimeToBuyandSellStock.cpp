#include<iostream>
#include<vector>

using namespace std;

int main(){

vector<int>a{7,6,5,4,3,2};
int mini = a[0];
int profit = 0;

for(int i = 0;i<a.size();i++){

    if(a[i]<mini)
        mini = a[i];
    else
        profit = max(profit,a[i]-mini);
}

cout<<profit;
return 0;
}
