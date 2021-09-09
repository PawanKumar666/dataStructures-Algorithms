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

int findCommonAncestor(node* root,int p,int q){

if(root == NULL) return NULL;

if(root->val == p || root->val == q) return root->val;

int left = findCommonAncestor(root->left,p,q);
int right = findCommonAncestor(root->right,p,q);

if(left == NULL) return right;
else if(right == NULL) return left;
else return root->val;
}

int main(){

node* root = new node(5);
root->left = new node(2);
root->right = new node(7);
root->left->right = new node(3);
root->left->left = new node(1);
root->right->left = new node(6);
root->right->right = new node(8);

cout<<findCommonAncestor(root,3,6);
}
