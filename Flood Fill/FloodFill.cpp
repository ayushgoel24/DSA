#include<bits/stdc++.h>
class Solution {
private:
    void runDFS(vector<vector<int>>& image, int startingColor, int finalColor, int sr, int sc, int deltaDirection[]) {
        
        if(sr<0 || sr>=image.size() || sc<0 || sc>= image[0].size() || image[sr][sc] == finalColor || image[sr][sc] != startingColor) return;
        
        image[sr][sc] = finalColor;
        
        for (int i=0; i<4; i++) {
            int neighRow = sr + deltaDirection[i];
            int neighCol = sc + deltaDirection[i+1];
            runDFS(image, startingColor, finalColor, neighRow, neighCol, deltaDirection);
        }
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<bool>> vis(image.size(), vector<bool>(image[0].size(), false));
        // runBFS(image, color, sr, sc, vis);
        
        int deltaDirection[] = {-1, 0, 1, 0, -1};
        runDFS(image, image[sr][sc], color, sr, sc, deltaDirection);
        
        return image;
    }
};