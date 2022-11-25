// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution{
private:
    void dfs(int i, int j, int n, int m, vector<vector<char>> &mat, vector<vector<bool>> &vis, int neighLoc[]) {
        vis[i][j] = true;
        for (int k=0; k<4; k++) {
            int r = i+neighLoc[k];
            int c = j+neighLoc[k+1];
            if (r>=0 && r<n && c>=0 && c<m && !vis[r][c] && mat[r][c] == 'O')
                dfs(r, c, n, m, mat, vis, neighLoc);
        }
    }
    
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int neighLoc[] = {-1, 0, 1, 0, -1};
        
        for (int j=0; j<m; j++) {
            if ( mat[0][j] == 'O' && !vis[0][j] )
                dfs(0, j, n, m, mat, vis, neighLoc);

            if ( mat[n-1][j] == 'O' && !vis[n-1][j] ) 
                dfs(n-1, j, n, m, mat, vis, neighLoc);
        }
        
        for (int i=1; i<n-1; i++) {
            if ( mat[i][0] == 'O' && !vis[i][0] )
                dfs(i, 0, n, m, mat, vis, neighLoc);

            if ( mat[i][m-1] == 'O' && !vis[i][m-1] ) 
                dfs(i, m-1, n, m, mat, vis, neighLoc);
        }
        
        for (int i=1; i<n-1; i++)
            for (int j=1; j<m-1; j++)
                if (mat[i][j] == 'O' && !vis[i][j])
                    mat[i][j] = 'X';
        
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}