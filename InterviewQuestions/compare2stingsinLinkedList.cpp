#include<bits/stdc++.h>

struct node{

char c;
node* next;
node(char data){
c = data;
next = NULL;
}
};
using namespace std;

int compareTwoLists(node* head1,node* head2){

if(head1 == NULL && head2 == NULL) return 0;
if(head1 == NULL) return -1;
if(head2 == NULL) return 1;

while(head1 && head2){
    if(head1->c != head2->c) break;
    head1 = head1->next;
    head2 = head2->next;
}

if(head1 && head2){
    if(head1->c > head2->c)return 1;
    else
        return -1;
}

if(!head1 && head2) return -1;
if(!head2 && head1) return 1;

return 0;
}
int main(){

node* head1 = new node('s');
head1->next = new node('t');
head1->next->next = new node('r');
head1->next->next->next = new node('a');
head1->next->next->next->next = new node('n');
head1->next->next->next->next->next = new node('g');
head1->next->next->next->next->next->next = new node('e');

node* head2 = new node('s');
head2->next = new node('t');
head2->next->next = new node('r');

cout<<compareTwoLists(head1,head2);
return 0;
}
