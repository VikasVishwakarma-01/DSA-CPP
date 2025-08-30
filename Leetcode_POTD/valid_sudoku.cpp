/*
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
1. Each row must contain the digits 1-9 without repetition.
2. Each column must contain the digits 1-9 without repetition.
3. Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:
- A Sudoku board (partially filled) could be valid but is not necessarily solvable.
- Only the filled cells need to be validated according to the mentioned rules.
*/

#include <bits/stdc++.h>
using namespace std;
bool isValidSudoku(vector<vector<char>>& board) {
    int n = 9;

    // Check rows
    for(int i = 0; i < n; i++){
        unordered_set<char> set;
        for(int j = 0; j < n; j++){
            char val = board[i][j];
            if(val != '.'){
                if(set.find(val) != set.end()) return false;
                set.insert(val);
            }
        }
    }

    // Check columns
    for(int j = 0; j < n; j++){
        unordered_set<char> set;
        for(int i = 0; i < n; i++){
            char val = board[i][j];
            if(val != '.'){
                if(set.find(val) != set.end()) return false;
                set.insert(val);
            }
        }
    }

    // Check 3x3 subgrids
    for(int blockRow = 0; blockRow < 9; blockRow += 3){
        for(int blockCol = 0; blockCol < 9; blockCol += 3){
            unordered_set<char> set;
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    char val = board[blockRow + i][blockCol + j];
                    if(val != '.'){
                        if(set.find(val) != set.end()) return false;
                        set.insert(val);
                    }
                }
            }
        }
    }

    return true;
}

int main(){
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    bool ans = isValidSudoku(board);
    cout<<ans<<endl;

    return 0;
}