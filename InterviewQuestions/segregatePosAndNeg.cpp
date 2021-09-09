#include<iostream>

using namespace std;

int main(){

int a[10] = {-1,1,-2,2,-3,3,-4,-5,5,4};
int left = 0;
int right = 0;

while(right< (sizeof(a)/sizeof(a[0])) && left<=right){
    if(a[right] < 0){
        swap(a[left],a[right]);
        left++;
        right++;
    }
    else if(a[right] >=0)
        right++;
}

for(int it : a)
    cout<<it<<" ";
return 0;
}
