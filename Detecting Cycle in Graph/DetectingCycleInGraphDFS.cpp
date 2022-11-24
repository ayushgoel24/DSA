#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
    private:
        bool detectCycle(int node, int parent, vector<int> adj[], bool vis[]) {
            vis[node] = true;
            
            for(auto neighbour : adj[node]) {
                if (!vis[neighbour])
                    if (detectCycle(neighbour, node, adj, vis)) return true;                    
                else if  (neighbour != parent) return true;
            }
            return false;
        }

    public:
        bool isCycle(int V, vector<int> adj[]) {
            bool vis[V] = {false};
            for (int i=0; i < V; i++) {
                if (!vis[i]) {
                    if (detectCycle(i, -1, adj, vis)) return true;
                }
            }
            return false;
        }
};
