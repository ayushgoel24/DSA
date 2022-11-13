#include<bits/stdc++.h>

class Solution {
public:
    
    void runBFS(vector<vector<char>>& grid, int row, int col, vector<vector<bool>>& vis, int deltaDirection[]) { 
        vis[row][col] = true;
        queue<pair<int, int>> island;
        island.push({row, col});
        
        while(!island.empty()) {
            int nRow = island.front().first;
            int nCol = island.front().second;
            island.pop();
            for(int i=0; i<4; i++) {
                int neighRow = nRow + deltaDirection[i];
                int neighCol = nCol + deltaDirection[i+1];
                if (neighRow >= 0 && neighRow < grid.size() && neighCol >= 0 && neighCol < grid[0].size() && !vis[neighRow][neighCol] && grid[neighRow][neighCol] == '1') {
                            vis[neighRow][neighCol] = true;
                            island.push({neighRow, neighCol});
                        }
            }
        }
    }
    
    void runDFS(vector<vector<char>>& grid, int row, int col, vector<vector<bool>>& vis, int deltaDirection[]) { 
        
        if (row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() && !vis[row][col] && grid[row][col] == '1') {
            vis[row][col] = true;
            for (int i=0; i<4; i++) {
                int neighRow = row + deltaDirection[i];
                int neighCol = col + deltaDirection[i+1];
                runDFS(grid, neighRow, neighCol, vis, deltaDirection);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        int deltaDirection[] = {-1, 0, 1, 0, -1};
        int count = 0;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (!vis[row][col] && grid[row][col] == '1') {
                    runDFS(grid, row, col, vis, deltaDirection);
                    count++;    
                }
            }
        }
        return count;
    }
};