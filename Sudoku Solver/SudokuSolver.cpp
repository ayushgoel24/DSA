#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canNumBeAdded( vector<vector<char>>& board, int row, int col, char num ) {
        for ( int i = 0; i < 9; i++ ) {
            if ( board[row][i] == num ) return false;
            if ( board[i][col] == num ) return false;
            if ( board[(row / 3) * 3 + (i / 3)][(col / 3) * 3 + (i % 3)] == num ) return false;
        }
        return true;
    }

    bool solveSudokuInternal(vector<vector<char>>& board) {
        for ( int i = 0; i < board.size(); i++ ) {
            for ( int j = 0; j < board[0].size(); j++ ) {
                if ( board[i][j] == '.' ) {
                    for ( char c = '1'; c <= '9'; c++ ) {
                        if ( canNumBeAdded( board, i, j, c ) ) {
                            board[i][j] = c;
                            if ( solveSudokuInternal( board ) ) return true;
                            else board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuInternal( board );
    }
};