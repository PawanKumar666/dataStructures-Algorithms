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

void preOrderTraversal(node* root){

if(root == NULL)
    return;
cout<<root->data<<" ";
preOrderTraversal(root->left);
preOrderTraversal(root->right);

}

void postOrderTraversal(node* root){

if(root == NULL)
    return;
postOrderTraversal(root->left);
postOrderTraversal(root->right);
cout<<root->data<<" ";

}

node* findMin(node* root){

while(root->left != NULL)
    root = root->left;
return root;
}

node* Delete(node* root,int delElement){

if(root == NULL){
    return root;
}
else if(delElement > root->data)
    root->right = Delete(root->right,delElement);
else if(delElement < root->data)
    root->left = Delete(root->left,delElement);
else{
    if(root->left == NULL && root->right == NULL){
        delete root;
        root = NULL;
    }
    else if(root->left == NULL){
        node* forDelete = root;
        root = root->right;
        delete forDelete;
    }
    else if(root->right == NULL){
        node* forDelete = root;
        root = root->left;
        delete forDelete;
    }
    else{
        node* minNode = findMin(root->right);
        root->data = minNode->data;
        root->right = Delete(root->right,minNode->data);
    }
}
return root;
}

int main(){

node* root = NULL;

int op = 0;
while(op != -1){

    cout<<endl<<"1 : Insert 2 : Search 3 : InOrderTraversal 4 : PreOrder traversal 5 : PostOrderTraversal 6 : Delete -1 : Exit"<<endl;
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

    case 4: preOrderTraversal(root);
    break;

    case 5: postOrderTraversal(root);
    break;

    case 6: int delElement;
    cout<<"Enter element to delete"<<endl;
    cin>>delElement;
    root = Delete(root,delElement);
    break;

    case -1:cout<<"Exiting the loop"<<endl;
    break;

    default:cout<<"Enter valid input"<<endl;

    }
}
return 0;
}
