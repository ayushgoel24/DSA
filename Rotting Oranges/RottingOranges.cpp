#include <bits/stdc++.h>

class Solution {
    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> gridCopy = grid;
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        int deltaRow[] = {-1, 0, 1, 0};
        int deltaCol[] = {0, 1, 0, -1};

        queue<pair<pair<int,int>, int>> cont;

        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (!vis[row][col] && gridCopy[row][col] == 2) {
                    cont.push({{row, col}, 0});
                    vis[row][col] = true;
                }
            }
        }

        int max_t = 0;
        while(!cont.empty()) {
            int row = cont.front().first.first;
            int col = cont.front().first.second;
            int t = cont.front().second;
            cont.pop();
            for (int i=0; i<4; i++) {
                int nRow = row + deltaRow[i];
                int nCol = col + deltaCol[i];
                if (nRow >= 0 && nRow < gridCopy.size() && nCol >= 0 && nCol < gridCopy[0].size() && !vis[nRow][nCol] && gridCopy[nRow][nCol] == 1) {
                    vis[nRow][nCol] = true;
                    gridCopy[nRow][nCol] = 2;
                    cont.push({{nRow, nCol}, t+1});
                    max_t = max(max_t, t+1);
                }
            } 
        }
        
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (gridCopy[row][col] == 1) return -1;
            }
        }
        return max_t;
    }
};