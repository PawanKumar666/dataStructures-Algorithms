#include<iostream>
#include<string>
#include<stack>

using namespace std;

bool isPair(char open,char close){

if(open == '(' && close == ')')return true;
if(open == '{' && close == '}')return true;
if(open == '[' && close == ']')return true;
return false;
}

bool isBalanced(string S){

if(S[0] == '\0')
    cout<<"The string is empty"<<endl;
else{
    stack<char> Stack;
    for(int i=0;i<S.length();i++){

        if(S[i] == '(' || S[i] == '{' || S[i] == '[')
            Stack.push(S[i]);
        else if(S[i] == ')' || S[i] == '}' || S[i] == ']'){
            if(Stack.empty() || !isPair(Stack.top(),S[i]))
                return false;
            else
                Stack.pop();
        }
        else
            continue;

    }
    if(Stack.empty())
        return true;
    else
        return false;
}
}
int main(){

string S;
cout<<"Provide the input to check";
getline(cin,S);

if(isBalanced(S))
    printf("The expression is balanced");
else
    printf("The expression is not balanced");
return 0;
}
