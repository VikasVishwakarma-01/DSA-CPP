class Solution {
public:
    vector<vector<int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    int solve(int cell, int x, int y, vector<vector<int>>& board) {
       
        int n = board.size();
        int m = board[0].size();

        int cnt = 0;
        for(auto &d: dir) {
            int i = x + d[0];
            int j = y + d[1];
            if(i >= 0 && i < n && j >= 0 && j < m) 
                cnt += board[i][j];
        }

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