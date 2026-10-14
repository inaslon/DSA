class Solution {
    using t = tuple<int, int, int>;
    struct D {
        int dr, dc;
    };

    vector<D> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();

        priority_queue<t, vector<t>, greater<t>> pq;
        vector<vector<int>> time(n, vector<int>(n, 1e9));

        pq.push({grid[0][0], 0, 0});
        time[0][0] = grid[0][0];

        int maxh = -1;
        while (!pq.empty()) {
            auto [t, r, c] = pq.top();
            pq.pop();

            if (r == n - 1 && c == n - 1)
                return t;

            for (auto d : dir) {
                int nr = r + d.dr;
                int nc = c + d.dc;

                if (nr < 0 || nc < 0 || nc >= n || nr >= n) {
                    continue;
                }

                int nt = max(t, grid[nr][nc]);
                if (time[nr][nc] > nt) {
                    pq.push({nt, nr, nc});
                    time[nr][nc] = nt;
                }
            }
        }

        return 0;
    }
};