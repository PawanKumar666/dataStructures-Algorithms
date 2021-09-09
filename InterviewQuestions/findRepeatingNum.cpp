/*Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.*/

#include<iostream>

using namespace std;

int main(){

int a[5] = {3,1,3,4,2};
int slow = a[a[0]];
int fast = a[slow];

while(slow!=fast){
    slow = a[slow];
    fast = a[a[fast]];
}
fast = a[0];
while(slow!=fast){
    fast = a[fast];
    slow = a[slow];
}
cout<<slow;
return 0;
}
