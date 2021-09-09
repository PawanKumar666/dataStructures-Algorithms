#include<bits/stdc++.h>

using namespace std;

int main(){

vector<pair<int,int>>pairVector;
vector<pair<int,int>>resultVector;
pairVector.push_back({1,3});
pairVector.push_back({8,10});
pairVector.push_back({2,6});
pairVector.push_back({9,9});
pairVector.push_back({15,18});
pair<int,int> temp = pairVector[0];
sort(pairVector.begin(),pairVector.end());
for(int i = 0;i<pairVector.size();i++){
    if(pairVector[i].second >= pairVector[i+1].first)
        temp = make_pair(pairVector[i].first,max(pairVector[i].second,pairVector[i+1].second));
    else
        cout<<temp.first<<" " <<temp.second<<endl;
return 0;
    }
}
