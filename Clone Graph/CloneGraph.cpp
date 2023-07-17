#include <iostream>
#include <unordered_map>

using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> mp;
    Node* dfs(Node* node) {
        Node* clone = new Node(node->val);
        mp[node] = clone;
        for(auto neigh : node->neighbors) {
            if (mp.find(neigh) != mp.end()) clone->neighbors.push_back(mp[neigh]);
            else {
                
                clone->neighbors.push_back(dfs(neigh));
            }
        }
        return clone;
    }

    Node* cloneGraph(Node* node) {
        
        if (node == NULL) return NULL;
        // if (node->neighbors.size() == 0) {
        //     Node* clone = new Node(node->val);
        //     return clone;
        // }
        return dfs(node);
    }
};