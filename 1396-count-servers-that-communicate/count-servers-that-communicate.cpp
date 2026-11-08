class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        unordered_map<int, vector<int>> adj;

        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    continue;
                for (int k = j + 1; k < n; k++) {
                    if (grid[i][j] == 1 && grid[i][k] == 1) {
                        int u = i * n + j;
                        int v = i * n + k;
                        adj[u].push_back(v);
                        adj[v].push_back(u);
                    }
                }

                for (int s = i + 1; s < m; s++) {
                    if (grid[i][j] == 1 && grid[s][j] == 1) {
                        int u = i * n + j;
                        int v = s * n + j;
                        adj[u].push_back(v);
                        adj[v].push_back(u);
                    }
                }
            }
        }

        return adj.size();
    }
};