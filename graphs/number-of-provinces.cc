/*
There are n cities. Some of them are connected, while some are not. 
If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

 

Example 1:


Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
Example 2:


Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
*/

class Solution {
    void exploreProvince(int curr, unordered_map<int, vector<int>> &g, vector<int> &visited) {
        if (visited[curr] == 1) return;
        visited[curr] = 1;

        for (int neighbour : g[curr]) {
            exploreProvince(neighbour, g, visited);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        unordered_map<int, vector<int>> g;

        // treat each 1 as an edge, remove self edges
        for (int i = 0; i < n; i++) {
            // each vector is the neighbour set of i
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }

        int provinces = 0;
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {exploreProvince(i, g, visited); provinces += 1;}
        }

        return provinces;
    }
};
