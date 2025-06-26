#include<bits/stdc++.h>
using namespace std;

class Solution {

    public:
        bool solve(vector<vector<char>>& board) {
            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board.size(); j++) {
                    if (board[i][j] == '.') {
                        for (char c = '1'; c <= '9'; c++) {  // FIX: Correct character range
                            if (isvalid(board, i, j, c)) {
                                board[i][j] = c;
    
                                if (solve(board)) {
                                    return true;
                                } else {
                                    board[i][j] = '.';  // Backtrack
                                }
                            }
                        }
                        return false;
                    }
                }
            }
            return true;
        }
    
        bool isvalid(vector<vector<char>>& board, int row, int col, char c) { // FIX: Pass by reference
            for (int i = 0; i < 9; i++) {  // FIX: Should always iterate from 0 to 8
                if (board[i][col] == c || board[row][i] == c || 
                    board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) {
                    return false;
                }
            }
            return true;
        }
    
        void solveSudoku(vector<vector<char>>& board) {
            solve(board);
        }
    };