/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

    1. Each of the digits 1-9 must occur exactly once in each row.
    2. Each of the digits 1-9 must occur exactly once in each column.

Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.
*/

#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<char> > &board, int r, int c, int num) {
    // row check
    for(int i = 0; i < 9; i++) {
        if(board[r][i] -'0' == num) return false;
    }
    //col check
    for(int i = 0; i < 9; i++) {
        if(board[i][c] -'0' == num) return false;
    }

    int x = (r/3)*3;
    int y = (c/3)*3;

    for(int i = x; i < x+3; i++) {
        for(int j = y; j < y+3; j++) {
            if(board[i][j] -'0' == num) return false;
        }
    }
    return true;
}

bool f(vector<vector<char> > &board, int r, int c) {
    if(r == 9) return true;
    if(c == 9) return f(board, r + 1, 0);
    if(board[r][c] != '.') return f(board, r, c + 1);
    for(int j = 1; j <= 9; j++) {
        if(isSafe(board, r, c, j)) {
            board[r][c] = '0'+ j;

            bool retval = f(board, r, c+1);
            if(retval) return true;
            board[r][c] = '.';
        }
    }
    return false;
}
void solveSudoku(vector<vector<char>>& board) {
    f(board, 0, 0);
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

    solveSudoku(board);

    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[i].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}