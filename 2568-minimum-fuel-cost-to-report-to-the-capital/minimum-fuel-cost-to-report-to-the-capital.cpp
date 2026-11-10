class Solution {
    using ll = long long;
    ll ans = 0;
    ll dfs(int u, int p, int seats, vector<vector<int>>& adj) {

        int people = 1;
        for (int v : adj[u]) {
            if (v == p)
                continue;
            int child = dfs(v, u, seats, adj);

            ans += ceil(double(child) / seats);

            people += child;
        }

        return people;
    }

public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;

        vector<vector<int>> adj(n);

        for (auto& e : roads) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, -1,seats,adj);

        return ans;
    }
};