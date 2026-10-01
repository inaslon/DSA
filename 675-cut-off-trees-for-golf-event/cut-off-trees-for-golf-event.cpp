class Solution {
    using t = tuple<int, int, int>;

    struct D {
        int dr;
        int dc;
    };

    vector<D> dir{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int m;
    int n;
    int bfs(int r, int c, int destx, int desty, vector<vector<int>>& forest) {
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vis[r][c] = true;
        q.push({r, c});

        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [x, y] = q.front();
                q.pop();
                if (x == destx && y == desty) {

                    return steps;
                }

                for (auto d : dir) {
                    int nr = x + d.dr;
                    int nc = y + d.dc;
                    if (nr < 0 || nc < 0 || nr >= m || nc >= n)
                        continue;
                    if (forest[nr][nc] == 0) {
                        continue;
                    }
                    if (!vis[nr][nc]) {
                        vis[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
            steps++;
        }
        return -1;
    }

public:
    int cutOffTree(vector<vector<int>>& forest) {
        m = forest.size();
        n = forest[0].size();

        priority_queue<t, vector<t>, greater<t>> pq;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (forest[i][j] == 0 || forest[i][j] == 1) {
                    continue;
                }

                pq.push({forest[i][j], i, j});
            }
        }
        int ans = 0;
        int i = 0, j = 0;
        if (pq.empty())
            return 0;
        while (!pq.empty()) {
            auto [h, x, y] = pq.top();
            pq.pop();
            int temp = bfs(i, j, x, y, forest);
            if (temp == -1) {
                return -1;
            }
            ans += temp;
            i = x;
            j = y;
        }
        if (forest[0][0] == 0) {
            return -1;
        }
        return ans;
    }
};