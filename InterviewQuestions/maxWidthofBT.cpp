#include<iostream>
#include<queue>

struct node{
int data;
node* left;
node* right;
};

using namespace std;

node* newNode(int data){
node* temp = new node();
temp->data = data;
temp->right=NULL;
temp->left=NULL;
return temp;
}

void maxWidth(node* root){

if(root = NULL){cout<<"Tree is empty"<<endl;return;}
queue<node *>myQueue;
int width = 0;
myQueue.push(root);
while(!myQueue.empty()){
    int count = myQueue.size();
    width = max(width,count);
    while(count--){
    node* temp = myQueue.front();
    myQueue.pop();
    if(temp->left != NULL)myQueue.push(temp->left);
    if(temp->right!= NULL)myQueue.push(temp->right);
    }
}
cout<<"The max-width of the tree is "<<width<<endl;
}

int main(){

node* root = newNode(1);
root->left = newNode(2);
root->right = newNode(3);
root->left->left = newNode(4);
root->left->right = newNode(5);
maxWidth(root);
return 0;
}
