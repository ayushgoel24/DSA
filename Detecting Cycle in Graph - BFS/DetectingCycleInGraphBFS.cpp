#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
    private:
        bool detectCycle(int src, vector<int> adj[], bool vis[]) {
            vis[src] = true;
            
            queue< pair<int, int> > q;
            q.push({src, -1});

            while(!q.empty()) {
                int node = q.front().first;
                int parent = q.front().second;
                q.pop();

                for(auto neighbour : adj[node]) {
                    if (!vis[neighbour]) {
                        vis[neighbour] = true;
                        q.push({neighbour, node});
                    } else if (parent != neighbour) {
                        return true;
                    }
                }
            }
            return false;
        }
    public:
        bool isCycle(int V, vector<int> adj[]) {
            bool vis[V] = {false};
            for (int i=0; i < V; i++) {
                if (!vis[i]) {
                    if (detectCycle(i, adj, vis)) return true;
                }
            }
            return false;
        }
};
