#include<bits/stdc++.h>

using namespace std;


bool rowChecker(vector<vector<char>> sudokuPuzzle, int row){

set<char> rowHash;
for(int i = 0;i<9;i++){
    if(rowHash.find(sudokuPuzzle[row][i]) != rowHash.end())
        return false;
    else if(sudokuPuzzle[row][i]!= '.')
        rowHash.insert(sudokuPuzzle[row][i]);
}
return true;
}

bool columnChecker(vector<vector<char>> sudokuPuzzle, int col){

set<char> colHash;
for(int i = 0;i<9;i++){
    if(colHash.find(sudokuPuzzle[i][col]) != colHash.end())
        return false;
    else if(sudokuPuzzle[i][col] != '.')
        colHash.insert(sudokuPuzzle[i][col]);
}
return true;
}

bool quadrantChecker(vector<vector<char>> sudokuPuzzle,int row, int col){

set<char> quadHash;
for(int i = 0;i<3;i++){
    for(int j = 0;j<3;j++){
        if(quadHash.find(sudokuPuzzle[i+row][j+col])!= quadHash.end())
            return false;
        else if(sudokuPuzzle[i+row][j+col] != '.')
            quadHash.insert(sudokuPuzzle[i+row][j+col]);
    }
}
return true;
}

int main(){

vector<vector<char>> sudokuPuzzle{ { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
                         { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
                         { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
                         { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
                         { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
                         { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
                         { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
                         { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
                         { '.', '.', '.', '.', '8', '.', '.', '7', '9' } };


for(int i = 0;i<9;i++){
    for(int j = 0;j<9;j++){
        if(!(rowChecker(sudokuPuzzle,i) && columnChecker(sudokuPuzzle,j) && quadrantChecker(sudokuPuzzle,i-i%3,j-j%3))){
            cout<<"The puzzle is not valid in the quadrant starting from "<< i-i%3 <<" and "<< j- j%3<<endl;
            for(int k = i-i%3;k<(i-i%3)+3;k++){
                for(int l = j-j%3;l<(j-j%3)+3;l++){
                    cout<<sudokuPuzzle[k][l]<<" ";
                }
                cout<<endl;
            }
            return 0;
        }
    }
}

cout<<"The puzzle is valid throughout";
return 0;
}
