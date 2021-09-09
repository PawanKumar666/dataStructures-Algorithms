#include<iostream>
#include<algorithm>

struct item{
int value;
int weight;
};

using namespace std;

bool comp(item a, item b){
double res1 = a.value/(double)a.weight;
double res2 = b.value/(double)b.weight;

return res1>res2;
}
int main(){

item arr[3] = {{60,10},{100,20},{120,30}};

sort(arr,arr+3,comp);

int capacity=50;
int profit = 0;
int i=0;

while(capacity!=0){
    if(capacity-arr[i].weight >=0){
        capacity-=arr[i].weight;
        profit+=arr[i].value;
        cout<<capacity<<endl;
        cout<<profit<<endl;
    }
    else{
        profit+=(arr[i].value/arr[i].weight)*capacity;
        capacity = 0;
        break;
    }
    i++;
}
cout<<profit<<endl;
return 0;
}
