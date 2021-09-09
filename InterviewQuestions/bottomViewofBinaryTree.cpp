#include<bits/stdc++.h>

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

using namespace std;

int main(){

node* root = new node(5);
root->left = new node(2);
root->right = new node(7);
root->left->right = new node(3);
root->left->left = new node(1);
root->right->left = new node(6);
root->right->right = new node(8);

map<int,int> hashMap;
queue<pair<node*,int>> holder;

holder.push({root,0});

while(!holder.empty()){

    auto top = holder.front();
    holder.pop();
    hashMap[top.second] = top.first->val;
    if(top.first->left) holder.push({top.first->left,top.second-1});
    if(top.first->right) holder.push({top.first->right,top.second+1});
}

for(auto it : hashMap){
    cout<<it.first<< " "<<it.second<<endl;
}
return 0;
}
