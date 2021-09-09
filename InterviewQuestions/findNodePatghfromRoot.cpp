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

bool getPath(node* root,vector<int>& pathVector,int srchEle){

if(root == NULL) return false;

pathVector.push_back(root->val);

if(root->val == srchEle) return true;

if(getPath(root->left,pathVector,srchEle) || getPath(root->right,pathVector,srchEle)) return true;

pathVector.pop_back();

return false;
}
int main(){

node* root = new node(5);
root->left = new node(2);
root->right = new node(7);
root->left->right = new node(3);
root->left->left = new node(1);
root->right->left = new node(6);
root->right->right = new node(8);
root->right->right->left = new node(9);
root->right->right->left->right = new node(10);

vector<int>pathVector;

getPath(root,pathVector,10);

for(int i : pathVector)
    cout<<i<< " ";
return 0;
}
