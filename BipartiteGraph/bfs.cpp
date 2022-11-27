#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    bool check(int sNode, vector<int>adj[], vector<int>& color) {
        queue<int> q;
        q.push(sNode);
	    color[sNode] = 0;
        while(!q.empty()) {
	        int node = q.front();
	        q.pop();
	        for (auto it : adj[node]) {
	            if (color[it] == -1) {
	                q.push(it);
	                color[it] = !color[node];
	            } else if (color[it] == color[node]) {
	                return false;
	            }
	        }
	    }
	    return true;
    }
    
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V, -1);
	    for (int i=0; i<V; i++)
	        if (color[i] == -1)
	            if (check(i, adj, color) == false) return false;
	            
	    return true;
	}
};