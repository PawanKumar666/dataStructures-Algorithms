#include<bits/stdc++.h>

using namespace std;

struct node{
int val;
node* left;
node* right;
node(int data){
val=data;
left = NULL;
right =NULL;
}
};

void addLeft(node* root,vector<int>& result){

if(root == NULL) return;
addLeft(root->left,result);
result.push_back(root->val);
}

void addRight(node* root,vector<int>& result){

if(root == NULL) return;
result.push_back(root->val);
addRight(root->right,result);
}

int main(){

node* root = new node(5);
root->left = new node(2);
root->right = new node(7);
root->left->right = new node(3);
root->left->left = new node(1);
root->right->left = new node(6);
root->right->right = new node(8);

vector<int> result;
addLeft(root->left,result);
result.push_back(root->val);
addRight(root->right,result);

for(int i: result)
    cout<<i<<" ";
return 0;
}
