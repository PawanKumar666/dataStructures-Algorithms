#include<iostream>
#include<map>

using namespace std;

struct treeNode{
int data;
treeNode* left;
treeNode* right;
};

treeNode* newNode(int data){
treeNode* temp = new treeNode;
temp->data = data;
temp->left = NULL;
temp->right= NULL;
return temp;
}

void verticalSum(treeNode* root,int hd,map<int,int>& myMap){

if(root == NULL)return;
verticalSum(root->left,hd-1,myMap);
myMap[hd]+=root->data;
verticalSum(root->right,hd+1,myMap);

}

int main(){

map<int,int>myMap;
map<int,int>::iterator it;

treeNode *root = newNode(1);
root->left = newNode(2);
root->right = newNode(3);
root->left->left = newNode(4);
root->left->right = newNode(5);
root->right->left = newNode(6);
root->right->right = newNode(7);

verticalSum(root,0,myMap);

for(it = myMap.begin();it!=myMap.end();it++)
    cout<<it->first<<" "<<it->second<<endl;

return 0;
}
