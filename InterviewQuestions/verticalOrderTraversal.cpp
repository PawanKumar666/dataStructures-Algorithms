#include<bits/stdc++.h>

using namespace std;

struct node{
int val;
node* left;
node* right;
node(int data){
val = data;
left = NULL;
right = NULL;
}
};

int main(){

node* root = new node(5);
root->left = new node(2);
root->right = new node(7);
root->left->right = new node(3);
root->left->left = new node(1);
root->right->left = new node(6);
root->right->right = new node(8);

queue<pair<int,node*>> holder;
holder.push(make_pair(0,root));

vector<vector<int>> result ;
//int maxi = 0;
while(!holder.empty()){
    auto temp = holder.front();
    holder.pop();
    result[abs(temp.first)].push_back(temp.second->val);
    //maxi = max(maxi,abs(temp.first));
    if(temp.second->left) holder.push(make_pair(temp.first-1,temp.second->left));
    if(temp.second->right) holder.push(make_pair(temp.first+1,temp.second->right));
}

for(int i = 0;i<result.size();i++){
    for(int j = 0;j<result[i].size();j++){
        cout<<result[i][j]<< " ";
    }
    cout<<endl;
}
return 0;
}
