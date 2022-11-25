#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {

public:
    vector<vector<int>> findDistanceMatrix( vector<vector<int>> grid ) {

        vector<vector<int>> distanceGrid( grid.size(), vector<int> ( grid[0].size(), 0 ) );
        vector<vector<bool>> visitedBlock( grid.size(), vector<bool> ( grid[0].size(), false ) );
        int neighborLoc[] = { -1, 0, 1, 0, -1 }; 

        queue<pair<pair<int, int>, int>> cont;

        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if ( grid[i][j] == 1 ) {
                    cont.push( { {i, j}, 0} );
                    visitedBlock[i][j] = true;
                }
            }
        }

        while(!cont.empty()) {
            int r = cont.front().first.first;
            int c = cont.front().first.second;
            int steps = cont.front().second;
            cont.pop();

            distanceGrid[r][c] = steps;

            for (int k=0; k<4; k++) {
                int dR = r + neighborLoc[k];
                int dC = c + neighborLoc[k+1];
                if (dR>=0 && dR<grid.size() && dC>=0 && dC<grid[0].size() && !visitedBlock[dR][dC]) {
                    cont.push( { {dR, dC}, steps+1} );
                    visitedBlock[dR][dC]=true;
                }
            }
        }
        return distanceGrid;
    }
};