

class Solution {

public:
    bool hasValidPath(vector<vector<int>>& grid) {
        vector<pair<int, int>> dir{
            {0, 1}, {1, 0}, {-1, 0}, {0, -1}}; // right down
        unordered_map<int, unordered_set<int>> mp;

        mp[1] = {0, 1}; // left, right
        mp[2] = {2, 3}; // up, down
        mp[3] = {0, 3}; // left, down
        mp[4] = {1, 3}; // right, down
        mp[5] = {0, 2}; // left, up
        mp[6] = {1, 2}; // right, up

        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        q.push({0, 0});

        vis[0][0] = true;
        while (!q.empty()) {

            auto [i, j] = q.front();
            q.pop();

            if (i == m - 1 && j == n - 1) {
                return true;
            }

            for (auto d : dir) {
                int ni = i + d.first;
                int nj = j + d.second;
                if (ni < 0 || nj < 0 || ni >= m || nj >= n)
                    continue;
                if (vis[ni][nj])
                    continue;

                int val1 = grid[i][j];
                int val2 = grid[ni][nj];
                if (d.first == 0 && d.second == 1) {
                    if (mp[val1].count(1) > 0 && mp[val2].count(0) > 0) {
                        vis[ni][nj] = true;
                        q.push({ni, nj});
                    }
                }

                else if (d.first == 0 && d.second == -1) { //
                    if (mp[val1].count(0) > 0 && mp[val2].count(1) > 0) {
                        vis[ni][nj] = true;
                        q.push({ni, nj});
                    }

                }

                else if (d.first == -1 && d.second == 0) { //
                    if (mp[val1].count(2) > 0 && mp[val2].count(3) > 0) {
                        vis[ni][nj] = true;
                        q.push({ni, nj});
                    }

                }

                else {
                    if (d.first == 1 && d.second == 0) {
                        if (mp[val1].count(3) > 0 && mp[val2].count(2) > 0) {
                            vis[ni][nj] = true;
                            q.push({ni, nj});
                        }
                    }
                }
            }
        }

        return false;
    }
};