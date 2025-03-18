#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool issafe(int n, int row, int col, vector<string>& board) {
            int duprow = row, dupcol = col;
    
            // Check left side of the same row
            while (dupcol >= 0) {
                if (board[row][dupcol--] == 'Q')
                    return false;
            }
    
            // Check upper-left diagonal
            duprow = row;
            dupcol = col;
            while (duprow >= 0 && dupcol >= 0) {
                if (board[duprow--][dupcol--] == 'Q')
                    return false;
            }
    
            // Check lower-left diagonal
            duprow = row;
            dupcol = col;
            while (duprow < n && dupcol >= 0) {
                if (board[duprow++][dupcol--] == 'Q')
                    return false;
            }
    
            return true;
        }
    
        void solve(int n, int col, vector<string>& board,
                   vector<vector<string>>& ans) {
            if (col == n) {
                ans.push_back(board);
                return;
            }
    
            for (int row = 0; row < n; row++) {
                if (issafe(n, row, col, board)) {
                    board[row][col] = 'Q'; // Place Queen
                    solve(n, col + 1, board, ans);
                    board[row][col] = '.'; // Backtrack
                }
            }
        }
    
        vector<vector<string>> solveNQueens(int n) {
            vector<vector<string>> ans;
            vector<string> board(n, string(n, '.'));
            solve(n, 0, board, ans);
            return ans;
        }
    };

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // optimized code 
    class Solution {
        public:
            void solve(int n, int col, vector<string>& board, 
                       vector<vector<string>>& ans, vector<int>& leftRow, 
                       vector<int>& upperDiagonal, vector<int>& lowerDiagonal) {
                if (col == n) {
                    ans.push_back(board);
                    return;
                }
        
                for (int row = 0; row < n; row++) {
                    if (!leftRow[row] && !upperDiagonal[n - 1 + col - row] && !lowerDiagonal[row + col]) {
                        // Place the queen
                        board[row][col] = 'Q';
                        leftRow[row] = upperDiagonal[n - 1 + col - row] = lowerDiagonal[row + col] = 1;
        
                        // Recur to place the rest of the queens
                        solve(n, col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal);
        
                        // Backtrack
                        board[row][col] = '.';
                        leftRow[row] = upperDiagonal[n - 1 + col - row] = lowerDiagonal[row + col] = 0;
                    }
                }
            }
        
            vector<vector<string>> solveNQueens(int n) {
                vector<vector<string>> ans;
                vector<string> board(n, string(n, '.')); // Initialize board with empty cells
                vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
        
                solve(n, 0, board, ans, leftRow, upperDiagonal, lowerDiagonal);
                return ans;
            }
        };