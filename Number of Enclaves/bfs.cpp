#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
    
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        int neighLoc[] = {-1, 0, 1, 0, -1};
        queue<pair<int,int>> q;

        int numOf1 = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                
                if (grid[i][j] == 1)
                    numOf1++;
                
                if ((i == 0 || i == n-1 || j == 0 || j == m-1) && grid[i][j] == 1) {
                    q.push({i, j});
                    grid[i][j] = 0;
                }
            }
        }

        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            numOf1--;
            for (int k=0; k<4; k++) {
                int r = i + neighLoc[k];
                int c = j + neighLoc[k+1];
                if (r>=0 && r<n && c>=0 && c<m && grid[r][c]==1 ) {
                    q.push({r,  c});
                    grid[r][c] = 0;
                }
            }
        }
        
        return numOf1;
    }
};