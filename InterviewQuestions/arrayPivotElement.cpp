#include<iostream>

using namespace std;

int solver(int *a,int len){

int left[len];
left[0] = INT_MIN;
int right = INT_MAX;

for (int i = 1; i < len; i++){
    left[i] = max(left[i-1], a[i-1]);
}

for (int i=len-1; i>=0; i--){
    if (left[i] < a[i] && right > a[i])
            return i;
    right= min(right, a[i]);
}
return -1;
}
int main(){
int *a,len;
cin>>len;
a= new int[len];
for(int i =0;i<len;i++)
    cin>>a[i];
cout<<solver(a,len);
return 0;
}
