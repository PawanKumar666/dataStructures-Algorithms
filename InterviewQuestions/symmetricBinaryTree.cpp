#include<bits/stdc++.h>

struct node{

int val;
node* left;
node* right;

node(int data){

val = data;
left =NULL;
right = NULL;
}
};

using namespace std;

bool symmetricChecker(node* root1,node* root2){

if(root1 == NULL || root2 ==NULL) return (root1 == root2);

return (root1->val == root2->val) && symmetricChecker(root1->right,root2->left) && symmetricChecker(root1->left,root2->right);
}
int main(){

node* root = new node(5);
root->left = new node(2);
root->right = new node(2);
root->left->right = new node(3);
root->left->left = new node(8);
root->right->left = new node(3);
root->right->right = new node(8);

if(symmetricChecker(root->left,root->right))
    cout<<"Is symmetric";
else
    cout<<"Isn't symmetric";
return 0;
}
