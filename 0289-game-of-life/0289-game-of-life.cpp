class Solution {
public:
    int solve(int cell, int i, int j, vector<vector<int>>& board) {
       
        int n = board.size();
        int m = board[0].size();

        int cnt = 0;
        if(i > 0 && j > 0) 
            cnt += board[i-1][j-1];
        if(j > 0) 
            cnt += board[i][j-1];
        if(i < n-1 && j > 0) 
            cnt += board[i+1][j-1];
        if(i > 0) 
            cnt += board[i-1][j];
        if(i < n-1) 
            cnt += board[i+1][j];
        if(i > 0 && j < m-1) 
            cnt += board[i-1][j+1];
        if(j < m-1) 
            cnt += board[i][j+1];
        if(i < n-1 && j < m-1) 
            cnt += board[i+1][j+1];


        if(cell == 1) {
            if(cnt < 2 or cnt > 3)
                return 0;
            return 1;
        }
        else {
            if(cnt == 3) 
                return 1;
        }

        return 0;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> ans = board;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans[i][j] = solve(board[i][j], i, j, board);
            }
        }

        board = ans;
    }
};