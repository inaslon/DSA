class Solution {
    vector<pair<int, int>> dir{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int m, n;
    vector<vector<int>> heights;
    void dfs(int r, int c, vector<vector<int>>& vis) {

        vis[r][c] = true;

        for (auto d : dir) {
            int nr = r + d.first;
            int nc = c + d.second;
            if (nr < 0 || nc < 0 || nr >= m || nc >= n)
                continue;

            if (!vis[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                dfs(nr, nc, vis);
            }
        }
    }

    // bool canflowA(int r, int c, vector<vector<int>> &vis) {

    //     if (r == m - 1 || c == n - 1) {
    //         return true;
    //     }

    //     for (auto d : dir) {
    //         int nr = r + d.first;
    //         int nc = c + d.second;
    //         if (nr < 0 || nc < 0 || nr >= m || nc >= n)
    //             continue;

    //         if (!vis[nr][nc] && heights[nr][nc] <= heights[r][c]) {
    //             vis[nr][nc] = true;
    //             if (canflowA(nr, nc, vis)) {
    //                 return true;
    //             }
    //         }
    //     }

    //     return false;
    // }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        this->heights = heights;
        m = heights.size();
        n = heights[0].size();

        vector<vector<int>> ans;
        vector<vector<int>> Pacefic(m, vector<int>(n, false));
        vector<vector<int>> Atlantic(m, vector<int>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) {

                    dfs(i, j, Pacefic);
                } 
                 if (i == m - 1 || j == n - 1) {
                    dfs(i, j, Atlantic);
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (Pacefic[i][j] && Atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};