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

queue<node*> holder;
holder.push(root);
while(!holder.empty()){
    node* temp = holder.front();
    cout<<temp->val<<" ";
    holder.pop();
    if(temp->left)
        holder.push(temp->left);
    if(temp->right)
        holder.push(temp->right);
}
return 0;
}
