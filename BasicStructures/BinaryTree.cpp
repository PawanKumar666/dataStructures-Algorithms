#include<iostream>

using namespace std;

struct node{
int data;
node* left;
node* right;
};

node* createNode(int inElement){

node* newNode = new node();
newNode->data = inElement;
newNode->left = NULL;
newNode->right = NULL;
return newNode;

}

node* Insert(node* root,int inElement){

if(root == NULL){
    root = createNode(inElement);
}
else if(root->data >= inElement)
    root->left = Insert(root->left,inElement);
else
    root->right = Insert(root->right,inElement);
return root;

}

int Search(node* root,int srchElement){

if(root == NULL)
    return -1;
else if(root->data == srchElement)
    return root->data;
else if(root->data < srchElement)
    return Search(root->right,srchElement);
else
    return Search(root->left,srchElement);

}

void inorderTraversal(node* root){

if(root == NULL)
    return;
inorderTraversal(root->left);
cout<<root->data<<" ";
inorderTraversal(root->right);

}

int main(){

node* root = NULL;

int op = 0;
while(op != -1){

    cout<<"1 : Insert 2 : Search 3 : InOrderTraversal -1 : Exit"<<endl;
    cin>>op;

    switch(op){

    case 1: int inElement;
    cout<<"Enter the element to insert"<<endl;
    cin>>inElement;
    root = Insert(root,inElement);
    break;

    case 2: int srchElement;
    cout<<"Enter the element to search"<<endl;
    cin>>srchElement;
    cout<<Search(root,srchElement)<<endl;
    break;

    case 3: inorderTraversal(root);
    break;

    case -1:cout<<"Exiting the loop"<<endl;
    break;

    default:cout<<"Enter valid input"<<endl;

    }
}
return 0;
}
