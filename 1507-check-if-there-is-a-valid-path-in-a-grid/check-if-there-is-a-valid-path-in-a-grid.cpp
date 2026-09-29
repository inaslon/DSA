

class DSU {

public:
    vector<int> parent, sz;
    DSU(int n) {
        parent.resize(n);
        sz.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        if (sz[a] < sz[b])
            swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];
    }
};

class Solution {

public:
    bool hasValidPath(vector<vector<int>>& grid) {
        vector<pair<int, int>> dir{{0, 1}, {1, 0}};
        unordered_map<int, unordered_set<int>> mp;

        mp[1] = {0, 1}; // left, right
        mp[2] = {2, 3}; // up, down
        mp[3] = {0, 3}; // left, down
        mp[4] = {1, 3}; // right, down
        mp[5] = {0, 2}; // left, up
        mp[6] = {1, 2}; // right, up

        int m = grid.size();
        int n = grid[0].size();

        DSU dsu(m * n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int cell1 = i * n + j;

                for (auto d : dir) {
                    int ni = i + d.first;
                    int nj = j + d.second;
                    if (ni >= m || nj >= n)
                        continue;
                    int cell2 = ni * n + nj;

                    int val1 = grid[i][j];
                    int val2 = grid[ni][nj];
                    if (d.first == 0 && d.second == 1) {
                        if (mp[val1].contains(1) && mp[val2].contains(0)) {
                            dsu.unite(cell1, cell2);
                        }
                    } else {
                        if (d.first == 1 && d.second == 0) {
                            if (mp[val1].contains(3)  && mp[val2].contains(2)) {
                                dsu.unite(cell1, cell2);
                            }
                        }
                    }
                }
            }
        }
        

        return dsu.find(0) == dsu.find(m*n-1);
        }
    };