#include<iostream>
#include<vector>

using namespace std;

int main(){

int n = 2;
int m = 3;

int dist = n+m-2;
int reqCalc = m-1;
double res = 1;

for(int i = 1;i<=reqCalc; i++)
    res = res*(dist-reqCalc+i)/i;

cout<<res;
return 0;
}
