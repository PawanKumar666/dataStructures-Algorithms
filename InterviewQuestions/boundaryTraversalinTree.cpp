#include<bits/stdc++.h>

using namespace std;

struct node{

int data;
node* left;
node* right;

node(int val){
data = val;
left = NULL;
right = NULL;
}

};

bool isLeaf(node* root){

return (!root->left && !root->right);
}

void getLeftBorder(node* root,vector<int>& result){

node* traverser = root->left;
while(traverser){
    if(!isLeaf(traverser)) result.push_back(traverser->data);
    if(traverser->left) traverser = traverser->left;
    else traverser = traverser->right;
}
}

void getRightBorder(node* root,vector<int>& result){

node* traverser = root->right;
stack<int> temp;
while(traverser){
    if(!isLeaf(traverser)) temp.push(traverser->data);
    if(traverser->right) traverser = traverser->right;
    else traverser = traverser->left;
}
while(!temp.empty()){
    result.push_back(temp.top());
    temp.pop();
}

}

void getLeaf(node* root,vector<int>& result){

if(isLeaf(root)){result.push_back(root->data); return;}
if(root->left)getLeaf(root->left,result);
if(root->right)getLeaf(root->right,result);
}

int main(){

node* root = new node(1);
root->left = new node(2);
root->right = new node(3);
root->right->left = new node(4);
root->right->right = new node(6);
root->right->left->right = new node(5);
root->right->left->right->left = new node(7);

vector<int> result;

if(root == NULL) return 0;
if(!isLeaf(root)) result.push_back(root->data);
getLeftBorder(root,result);
getLeaf(root,result);
getRightBorder(root,result);
for(int i : result)
    cout<<i<< " ";
return 0;
}
