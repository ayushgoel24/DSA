#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    bool checkDFS(int sNode, int colr, vector<int>adj[], vector<int>& color) {
        color[sNode] = colr;
        for (auto it : adj[sNode]) {
            if (color[it] == -1) {
                if (! checkDFS(it, !colr, adj, color)) return false;
            } else if (color[it] == color[sNode]) {
                return false;
            }
        }
        return true;
    }
    
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V, -1);
	    for (int i=0; i<V; i++)
	        if (color[i] == -1)
	            if (checkDFS(i, 0, adj, color) == false) return false;
	            
	    return true;
	}
};