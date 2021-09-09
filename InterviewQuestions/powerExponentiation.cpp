#include<iostream>

using namespace std;

int main(){

int num = 2;
int pow = -10;
int tempPow;
double ans = 1.0;
if(pow<0)tempPow = pow*(-1);
else
    tempPow = pow;
while(tempPow>0){
    if(tempPow%2 == 1){
        ans = ans*num;
        tempPow = tempPow-1;
    }
    else{
        num = num*num;
        tempPow = tempPow/2;
    }
}
if(pow<0)ans = (double)1.0/ans;
cout<<ans;
return 0;
}
