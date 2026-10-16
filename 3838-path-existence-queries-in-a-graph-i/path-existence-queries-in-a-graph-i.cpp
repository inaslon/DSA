class Solution {
    class DSU {
        vector<int> parent, sz;

    public:
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

public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {

        DSU dsu(n);
        for (int i = 1; i < n; i++) {
            if (abs(nums[i] - nums[i - 1]) <= maxDiff) {
                dsu.unite(i, i - 1);
            }
        }

        vector<bool> ans(queries.size(), false);

        for (int i = 0; i < queries.size(); i++) {
            auto q = queries[i];
            int a = dsu.find(q[0]);
            int b = dsu.find(q[1]);

            if (a == b) {
                ans[i] = true;
            }

        }
        return ans;
    }


};