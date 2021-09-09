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

void reversePreorder(node* root,int level,vector<int>& result){

if(root == NULL) return ;

if(level == result.size())
    result.push_back(root->val);
reversePreorder(root->right,level+1,result);
reversePreorder(root->left,level+1,result);
}

int main(){

node* root = new node(5);
root->left = new node(2);
root->right = new node(7);
root->left->right = new node(4);
root->left->right->left = new node(3);
root->left->left = new node(1);
root->right->left = new node(6);
root->right->right = new node(8);

vector<int> result;

reversePreorder(root,0,result);

for(int i : result)
    cout<<i<<" ";
return 0;
}
