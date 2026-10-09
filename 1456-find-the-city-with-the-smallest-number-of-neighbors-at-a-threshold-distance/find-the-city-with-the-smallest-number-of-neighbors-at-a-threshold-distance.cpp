class Solution {
    using p = pair<int, int>;
    unordered_map<int, vector<p>> adj;
    int threshold;
    int n;
    int bfs(int source) {
        priority_queue<p> pq;
        vector<int> dis(n, 1e9);
        pq.push({0, source});
        dis[source] = 0;

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            for (auto [v, w] : adj[u]) {
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    pq.push({dis[v], v});
                }
            }
        }

        int cnt = 0;
        for (int d : dis) {
            if (d == 0)
                continue;
            if (d <= threshold) {
                cnt++;
            }
        }

        return cnt;
    }

public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        this->n = n;
        threshold = distanceThreshold;
        for (auto e:edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        int mincity = 1e9;
        int ans = -1;
        for (int i = 0; i < n; i++) {
            int temp = bfs(i);
            if (temp <= mincity) {
                mincity = temp;
                ans = i;
            }
        }

        return ans;
    }
};