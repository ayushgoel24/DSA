#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        // Map to keep track of the number of characters that precede each character (in-degree).
        unordered_map<char, int> indegree;

        // Graph represented by a map where each character maps to a list of characters that follow it.
        unordered_map<char, vector<char>> graph;

        // Initialize the graph and in-degree map using all the characters from the input words.
        for (string word : words) {
            for (char c : word) {
                indegree[c] = 0; // Initialize in-degree to 0 for all characters.
                graph[c] = {};   // Initialize the adjacency list for each character.
            }
        }

        // Build the graph by comparing adjacent words to find character precedence.
        for (int i = 0; i < words.size() - 1; i++) {
            string word = words[i];
            string next_word = words[i + 1];

            // Check for invalid input where a prefix word appears after a word that starts with the prefix.
            if (word.size() > next_word.size() && word.substr(0, next_word.size()) == next_word) {
                return "";
            }

            // Find the first non-matching pair of characters and establish the ordering.
            for (int j = 0; j < min(word.size(), next_word.size()); j++) {
                if (word[j] != next_word[j]) {
                    graph[word[j]].push_back(next_word[j]); // Create an edge to the graph.
                    indegree[next_word[j]]++; // Increment the in-degree of the second character.
                    break; // Only the first character pair difference determines the order.
                }
            }
        }

        // The result string which will contain the characters in topological order.
        string ans = "";
        // Queue to perform the topological sort.
        queue<char> q;

        // Start with all characters that have an in-degree of 0.
        for (auto entry : indegree) {
            if (entry.second == 0) {
                q.push(entry.first);
            }
        }

        // Process the graph in topological order.
        while (!q.empty()) {
            char node = q.front(); q.pop();
            ans += node; // Append the current character to the result string.

            // Visit all the neighbors of the current character.
            for (char neighbor : graph[node]) {
                indegree[neighbor]--; // Decrement the in-degree of the neighboring character.
                // If the in-degree drops to 0, it's safe to process this character next.
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If we cannot determine the order for some characters (i.e., there's a cycle), return an empty string.
        if (ans.length() < indegree.size()) return "";

        // If there were no cycles, return the characters in topological order as the alphabet order of the alien language.
        return ans;
    }
};
