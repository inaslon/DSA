class Solution {
    vector<pair<int, int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    using ll = long long;

public:
    int countIslands(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    continue;
                }

                if (!vis[i][j]) {

                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vis[i][j] = true;
                    
                    ll sum = 0;

                    while (!q.empty()) {
                        auto [r, c] = q.front();
                        q.pop();

                       sum += grid[r][c];

                        for (auto d : dir) {
                            int nr = r + d.first;
                            int nc = c + d.second;

                            if (nr < 0 || nc < 0 || nr >= m || nc >= n ||
                                grid[nr][nc] == 0)
                                continue;

                            if (!vis[nr][nc]) {
                                q.push({nr, nc});
                                vis[nr][nc] = true;
                            }
                        }
                    }


                    if (sum % k == 0) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};