#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    void solveNQueensInternal( vector<vector<string>>& comb, vector<string>& board, int col, vector<bool>& leftNeigh, vector<bool>& upperDiagonalNeigh, vector<bool>& lowerDiagonalNeigh ) {
        if ( col == board.size() ) {
            comb.emplace_back( board );
            return;
        }
        for ( int row = 0; row < board.size(); row++ ) {
            if ( !leftNeigh[ row ] && !upperDiagonalNeigh[ ( board.size() - 1 ) + ( col - row )] && !lowerDiagonalNeigh[ row + col] ) {
                board[ row ][ col ] = 'Q';
                leftNeigh[ row ] = true, upperDiagonalNeigh[ ( board.size() -1 ) + ( col - row )] = true, lowerDiagonalNeigh[ row + col] = true;
                solveNQueensInternal( comb, board, col + 1, leftNeigh, upperDiagonalNeigh, lowerDiagonalNeigh );
                board[ row ][ col ] = '.';
                leftNeigh[ row ] = false, upperDiagonalNeigh[ ( board.size() -1 ) + ( col - row )] = false, lowerDiagonalNeigh[ row + col] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens( int n ) {
        vector<vector<string>> comb;
        vector<string> board( n );
        string s( n, '.' );
        for ( int i = 0; i < n; i++ ) board[i] = s;
        vector<bool> leftNeigh( n, false ), upperDiagonalNeigh( 2 * n - 1, false ), lowerDiagonalNeigh( 2 * n - 1, false );
        solveNQueensInternal( comb, board, 0, leftNeigh, upperDiagonalNeigh, lowerDiagonalNeigh );
        return comb;
    }
};