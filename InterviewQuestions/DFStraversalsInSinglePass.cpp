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

int findDepth(node* root){

if(root == NULL) return 0;
int ld = findDepth(root->left);
int rd = findDepth(root->right);

return 1+max(ld,rd);

}

int main(){

node* root = new node(2);
root->left = new node(1);
root->right = new node(3);

stack<pair<node*, int>> DFSStack;

vector<int> preOrder;
vector<int> inOrder;
vector<int> postOrder;

DFSStack.push({root,1});

while(!DFSStack.empty()){
    auto it = DFSStack.top();
    DFSStack.pop();
    if(it.second == 1){
        preOrder.push_back(it.first->data);
        it.second++;
        DFSStack.push(it);
        if(it.first->left!=NULL)
            DFSStack.push({it.first->left,1});
    }
    else if(it.second == 2){
        inOrder.push_back(it.first->data);
        it.second++;
        DFSStack.push(it);
        if(it.first->right!=NULL)
            DFSStack.push({it.first->right,1});
    }
    else
        postOrder.push_back(it.first->data);
}

for(int pre : preOrder)
    cout<<pre<<" ";
cout<<endl;

for(int in : inOrder)
    cout<<in<<" ";
cout<<endl;

for(int post : postOrder)
    cout<<post<<" ";
cout<<endl;

cout<< "The maximum depth of the tree is "<<findDepth(root) - 1;
return 0;
}
