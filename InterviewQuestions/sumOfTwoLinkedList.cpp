#include<iostream>

using namespace std;

struct Node{
int value;
Node* next;
};

Node *add_two_list(Node* head1,Node* head2){

        int carry = 0, first, second;
        Node *newhead = new Node(), *tail = newhead;
        while (head1 || head2 || carry) {
            if (head1) {
                first = head1->value;
                head1= head1->next;
            }
            else
                first = 0;

            if (head2) {
                second = head2->value;
                head2 = head2->next;
            }
            else
                second = 0;

            int temp = first+second+carry;
            tail->next = new Node();
            tail->next->value = temp%10;
            tail = tail->next;
            carry = temp/10;

        }
        return newhead->next;
}

int main(){

Node* head1 = new Node();
head1->value = 7;
head1->next->value=1;
head1->next->next->value=6;
head1->next->next->next = NULL;

Node* head2 = new Node();
head2->value = 5;
head2->next->value=9;
head2->next->next->value=2;
head2->next->next->next = NULL;

while(head1!=NULL){
    cout<<head1->value;
    head1 = head1->next;
}
Node* ans = add_two_list(head1,head2);


while(ans!=NULL){
    cout<<ans->value;
    ans = ans->next;
}
return 0;
}
