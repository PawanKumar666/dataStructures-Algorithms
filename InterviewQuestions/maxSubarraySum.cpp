#include<iostream>

using namespace std;

int main(){

int a[8] = {-2,-3,4,-1,-2,1,5,-3};
int maxi = a[0];
int sum = 0;
for(int i = 0;i<sizeof(a)/sizeof(a[0]);i++){
    sum+=a[i];
    maxi = max(maxi,sum);
    if(sum<0)sum = 0;
}
cout<<maxi;
return 0;
}
