/*

3446. Sort Matrix by Diagonals
You are given an n x n square matrix of integers grid.
Return the matrix such that:
 -The diagonals in the bottom-left triangle (including the middle diagonal) are sorted in non-increasing order.
 -The diagonals in the top-right triangle are sorted in non-decreasing order.

*/

#include <bits/stdc++.h>
using namespace std;

    vector<vector<int>> sortMatrix(vector<vector<int>>& grid){
        int n = grid.size();
        vector<vector<int>> ans(n, vector<int>(n));
        vector<vector<int>> diag(2 * n + 1);

        // Group elements by (i - j + n) to avoid negative indices
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                diag[i - j + n].push_back(grid[i][j]);

        // Sort each diagonal
        for(int k = 0; k < 2 * n + 1; ++k){
            if(k < n) // bottom-left part → descending
                sort(diag[k].begin(), diag[k].end(), greater<int>());
            else       // top-right part → ascending
                sort(diag[k].begin(), diag[k].end());
        }

        // Refill the matrix
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                int idx = i - j + n;
                ans[i][j] = diag[idx].back(); // take from end
                diag[idx].pop_back();
            }
        }

        return ans;
    }

    int main(){
        vector<vector<int>> grid = {{1,7,3}, 
                                    {9,8,2}, 
                                    {4,5,6}};
        grid = sortMatrix(grid);
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid.size(); j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        return 0;
    }
