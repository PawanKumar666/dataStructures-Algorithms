#include<iostream>
#define MAX_SIZE 12

using namespace std;

int main(){

int a[MAX_SIZE];

for(int i=0;i<MAX_SIZE;i++){

    cin>>a[i];
}
int i = 0;
int zero = 0;
int one = 0;
int two = 0;

for(int i=0;i<MAX_SIZE;i++){
    if(a[i] == 0)
        zero++;
    else if(a[i]==1)
        one++;
    else
        two++;
}

while(zero){
    a[i++] = 0;
    zero--;
}
while(one){
    a[i++] = 1;
    one--;
}
while(two){
    a[i++] = 2;
    two--;
}
for(int i=0;i<MAX_SIZE;i++)
    cout<<a[i]<<" ";
return 0;
}

