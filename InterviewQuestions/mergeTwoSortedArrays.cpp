#include<iostream>
#include<vector>

using namespace std;

int main(){

vector<int>vect1{1,4,7,8,10};
vector<int>vect2{2,3,9};

int n = vect1.size();
int m = vect2.size();

int l=0;
int r = max(n,m);

while(l<=r){
    int cut1 = (l+n)/2;
    int cut2 = (n+m+1)/2-cut1;
    int l1 = cut1 ? INT_MIN : vect1[cut1-1];
    int l2 = cut2 ? INT_MIN : vect2[cut2-1];
    int r1 = cut1 == n ? INT_MAX : vect1[cut1];
    int r2 = cut2 == m ? INT_MAX : vect2[cut2];

    if(l1<=r2 && l2<=r1){
        if((n+m)%2)
            cout<<max(l1,l2)<<endl;
        else
            cout<<(max(l1,l2)+min(r1,r2))/2<<endl;
        break;
    }

    else if(l1>r2)
        r = cut1-1;
    else
        l = cut1+1;
}
return 0;
}
