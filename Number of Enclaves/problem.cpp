class Solution {
private:
    void dfs(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<bool>>& vis, int neighLoc[]) {
        if (i<0 || i>=n || j<0 || j>=m || vis[i][j] || grid[i][j] != 1)
            return;
        vis[i][j] = true;
        for (int k=0; k<4; k++) {
            int r = i + neighLoc[k];
            int c = j + neighLoc[k+1];
            dfs(r, c, n, m, grid, vis, neighLoc);
        }
    }
    
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int neighLoc[] = {-1, 0, 1, 0, -1};
        
        for (int j=0; j<m; j++) {
            if (grid[0][j] == 1 && !vis[0][j])
                dfs(0, j, n, m, grid, vis, neighLoc);
            if (grid[n-1][j] == 1 && !vis[n-1][j])
                dfs(n-1, j, n, m, grid, vis, neighLoc);
        }
        
        for (int i=1; i<n-1; i++) {
            if (grid[i][0] == 1 && !vis[i][0])
                dfs(i, 0, n, m, grid, vis, neighLoc);
            if (grid[i][m-1] == 1 && !vis[i][m-1])
                dfs(i, m-1, n, m, grid, vis, neighLoc);
        }
        
        int count = 0;
        for (int i=1; i<n-1; i++)
            for (int j=1; j<m-1; j++)
                if (grid[i][j] == 1 && !vis[i][j])
                    count++;
        
        return count;
    }
};