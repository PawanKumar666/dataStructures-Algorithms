#include<bits/stdc++.h>

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

using namespace std;

void inorder(node* root){

if(root == NULL) return;
inorder(root->left);
cout<<root->data<< " ";
inorder(root->right);

}

void preOrder(node* root){

if(root == NULL) return ;

cout<<root->data<<" ";
preOrder(root->left);
preOrder(root->right);

}

void postOrder(node* root){

if(root == NULL) return ;

postOrder(root->left);
postOrder(root->right);
cout<<root->data<<" ";

}

int main(){

node* root = new node(5);
root->left = new node(2);
root->right = new node(7);
root->left->right = new node(3);
root->left->left = new node(1);
root->right->left = new node(6);
root->right->right = new node(8);
cout<<"Inorder traversal is "<<endl;
inorder(root);
cout<<endl<<"Preorder traversal is "<<endl;
preOrder(root);
cout<<endl<<"Postorder traversal is "<<endl;
postOrder(root);

return 0;
}
