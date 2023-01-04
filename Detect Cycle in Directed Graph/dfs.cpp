#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    bool detectCycleDFS( int sNode, int V, vector<int> adj[], vector<bool>& vis, vector<bool>& pathVis) {
        vis[sNode] = true;
        pathVis[sNode] = true;

        for (auto it: adj[sNode]) {
            if (!vis[it]) {
                if ( detectCycleDFS( it, V, adj, vis, pathVis ) == true ) return true;
            } else if (pathVis[it]) {
                return true;
            }
        }

        pathVis[sNode] = 0;

        return false;
    }

public:
    bool isCyclic( int V, vector<int> adj[] ) {
        vector<bool> vis( V, false );
        vector<bool> pathVis( V, false );
        for ( int i=0; i < V; i++ ) {
            if ( !vis[i] ) {
                if ( detectCycleDFS( i, V, adj, vis, pathVis ) == true ) return true;
            }
        }
    }
};