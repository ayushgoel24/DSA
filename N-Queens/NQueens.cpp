#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    bool canQueenBePlaced( vector<string>& board, int row, int col ) {
        int rowNeigh = row;
        int colNeigh = col;

        // This will check for another Q is the same row.
        while ( colNeigh >= 0 ) {
            if ( board[ rowNeigh ][ colNeigh ] == 'Q') return false;
            colNeigh--;
        }

        colNeigh = col;
        while( rowNeigh >= 0 && colNeigh >= 0 ) {
            if ( board[ rowNeigh ][ colNeigh ] == 'Q') return false;
            rowNeigh--;
            colNeigh--;
        }

        rowNeigh = row;
        colNeigh = col;
        while( rowNeigh < board.size() && colNeigh >= 0 ) {
            if ( board[ rowNeigh ][ colNeigh ] == 'Q') return false;
            rowNeigh++;
            colNeigh--;
        }

        return true;
    }

    void solveNQueensInternal( vector<vector<string>>& comb, vector<string>& board, int col ) {
        if ( col == board.size() ) {
            comb.emplace_back( board );
            return;
        }
        for ( int row = 0; row < board.size(); row++ ) {
            if ( canQueenBePlaced( board, row, col ) ) {
                board[ row ][ col ] = 'Q';
                solveNQueensInternal( comb, board, col + 1 );
                board[ row ][ col ] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens( int n ) {
        vector<vector<string>> comb;
        vector<string> board( n );
        string s( n, '.' );
        for ( int i = 0; i < n; i++ ) board[i] = s;
        solveNQueensInternal( comb, board, 0 );
        return comb;
    }
};