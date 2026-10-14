class Solution {
    using p = pair<int, int>;
    struct D {
        int dr, dc;
    };

    vector<D> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();

        auto bfs = [&](int t) {
            queue<p> q;
            vector<vector<bool>> vis(n, vector<bool>(n, false));
            if (grid[0][0] > t)
                return false;

                
            q.push({0, 0});
            vis[0][0] = true;

            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();

                if (r == n - 1 && c == n - 1)
                    return true;

                for (auto d : dir) {
                    int nr = r + d.dr;
                    int nc = c + d.dc;

                    if (nr < 0 || nc < 0 || nc >= n || nr >= n ||
                        grid[nr][nc] > t) {
                        continue;
                    }

                    if (!vis[nr][nc]) {
                        q.push({nr, nc});
                        vis[nr][nc] = true;
                    }
                }
            }
            return false;
        };

        int low = 0;
        int high = 1e9;
        int ans;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (bfs(mid)) {
                ans = mid;
                high = mid - 1;

            } else {

                low = mid + 1;
            }
        }

        return ans;
    }
};