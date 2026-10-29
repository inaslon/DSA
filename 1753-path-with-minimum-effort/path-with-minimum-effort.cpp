class Solution {
    vector<pair<int, int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    using t = tuple<int, int, int>;

public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        priority_queue<t, vector<t>, greater<t>> pq;

        vector<vector<int>> vis(m, vector<int>(n, 1e9));

        pq.push({0, 0, 0});
        vis[0][0] = 0;

        while (!pq.empty()) {
            auto [e, r, c] = pq.top();
            pq.pop();

            if (r == m - 1 && c == n - 1)
                return e;

            for (auto d : dir) {

                int nr = r + d.first;
                int nc = c + d.second;

                if (nr < 0 || nc < 0 || nr >= m || nc >= n)
                    continue;
                int w = heights[nr][nc];
                int pw = heights[r][c];
                int ne = max(e, abs(w - pw));

                if (vis[nr][nc] > ne) {
                    vis[nr][nc] = ne;
                    pq.push({ne, nr, nc});
                }
            }
        }

        return -1;
    }
};