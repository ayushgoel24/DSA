#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
  private:
    void dfs(int r, int c, int n, int m, vector<vector<int>>& grid, vector<vector<bool>>& vis, vector<pair<int, int>>& ijpair, int brow, int bcol) {
        if (r<0 || r>=n || c<0 || c>=m || vis[r][c] || grid[r][c] != 1) return;

        vis[r][c] = 1;
        ijpair.push_back({r-brow,c-bcol});

        dfs(r-1,c,n,m,grid,vis,ijpair,brow,bcol);
        dfs(r,c+1,n,m,grid,vis,ijpair,brow,bcol);
        dfs(r+1,c,n,m,grid,vis,ijpair,brow,bcol);
        dfs(r,c-1,n,m,grid,vis,ijpair,brow,bcol);

    }

  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        set<vector<pair<int, int>>> setC;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    vector<pair<int, int>> ijpair;
                    dfs(i, j, n, m, grid, vis, ijpair, i, j);
                    setC.insert(ijpair);
                }
            }
        }
        return setC.size();
    }
};