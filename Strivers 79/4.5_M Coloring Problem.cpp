#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isSafe(int node, vector<vector<int>>& graph, vector<int>& color, int col) {
        for (int neighbor : graph[node]) {
            if (color[neighbor] == col) return false;
        }
        return true;
    }

    bool solve(int node, vector<vector<int>>& graph, vector<int>& color, int m) {
        if (node == graph.size()) return true;
        
        for (int c = 1; c <= m; c++) {
            if (isSafe(node, graph, color, c)) {
                color[node] = c;
                if (solve(node + 1, graph, color, m)) return true;
                color[node] = 0;
            }
        }
        return false;
    }

    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
        vector<vector<int>> graph(v);
        for (auto& edge : edges) {
            graph[edge.first].push_back(edge.second);
            graph[edge.second].push_back(edge.first);
        }
        
        vector<int> color(v, 0);
        return solve(0, graph, color, m);
    }
};

// using matrix
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isSafe(int node, vector<vector<int>>& graph, vector<int>& color, int col) {
        for (int i = 0; i < graph.size(); i++) {
            if (graph[node][i] == 1 && color[i] == col) return false;
        }
        return true;
    }

    bool solve(int node, vector<vector<int>>& graph, vector<int>& color, int m) {
        if (node == graph.size()) return true;
        
        for (int c = 1; c <= m; c++) {
            if (isSafe(node, graph, color, c)) {
                color[node] = c;
                if (solve(node + 1, graph, color, m)) return true;
                color[node] = 0;
            }
        }
        return false;
    }

    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
        vector<vector<int>> graph(v, vector<int>(v, 0));
        for (auto& edge : edges) {
            graph[edge.first][edge.second] = 1;
            graph[edge.second][edge.first] = 1;
        }
        
        vector<int> color(v, 0);
        return solve(0, graph, color, m);
    }
};
