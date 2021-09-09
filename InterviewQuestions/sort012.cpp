#include<iostream>

using namespace std;

int main(){

int a[12] = {0,1,1,0,1,2,1,2,0,0,0,1};
int low = 0;
int high = 11;
int mid = 0;

while(mid<=high){
    if(a[mid] == 0){
        if(low!=mid)
            swap(a[low],a[mid]);
        low++;
        mid++;
    }
    else if(a[mid] == 1)
        mid++;
    else{
        swap(a[mid],a[high]);
        high--;
    }
}
for(auto& it:a)
    cout<<it<<" ";
return 0;
}
