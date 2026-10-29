class Solution {
    using p = pair<int, int>;

public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        priority_queue<p, vector<p>, greater<p>> pq;

        vector<bool> vis(n, false);

        pq.push({0, 0});
        int cnt = 0;
        int ans = 0;
        while (!pq.empty() && cnt <= n - 1) {

            auto [cost, u] = pq.top();
            pq.pop();
            if (vis[u]) {
                continue;
            }
            vis[u] = true;
            cnt++;
            ans += cost;

            for (int v = 0; v < n; v++) {
                if (!vis[v]) {
                    int dis = abs(points[v][0] - points[u][0]) +
                              abs(points[v][1] - points[u][1]);

                    pq.push({dis, v});
                }
            }
        }

        return ans;
    }
};