class Solution {
    vector<pair<int, int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

public:
    int closedIsland(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        int ans  = 0;

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    continue;
                }

                if (!vis[i][j]) {

                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vis[i][j] = true;
                    set<pair<int, int>> st;

                    while (!q.empty()) {
                        auto [r, c] = q.front();
                        q.pop();

                        st.insert({r, c});

                        for (auto d : dir) {
                            int nr = r + d.first;
                            int nc = c + d.second;

                            if (nr < 0 || nc < 0 || nr >= m || nc >= n ||
                                grid[nr][nc] == 1)
                                continue;

                            if (!vis[nr][nc]) {
                                q.push({nr, nc});
                                vis[nr][nc] = true;
                            }
                        }
                    }

                    bool fine = true;

                    for (auto& [r, c] : st) {
                        for (auto d : dir) {
                            int nr = r + d.first;
                            int nc = c + d.second;

                            if (nr < 0 || nc < 0 || nr >= m || nc >= n){
                                fine = false; 
                                break;
                            }

                            if(st.count({nr,nc})) continue;

                            if(grid[nr][nc] == 0) {
                                fine = false;
                                break;
                            }

                        
                        }

                        if(!fine){
                            break;
                        }
                    }

                    if(fine){
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};