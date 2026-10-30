class Solution {
    using t = tuple<int, int, int>;

public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        unordered_map<int, vector<pair<int, int>>> adj;

        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<vector<int>> dis(n+1, vector<int>(k+1,1e9));

        priority_queue<t, vector<t>, greater<t>> pq; // w,node,consecutive 1

        pq.push({0, 0, 1});
        dis[0][1] = 0;

        while (!pq.empty()) {
            auto [d, u, consecutive] = pq.top();
            pq.pop();
            if (d > dis[u][consecutive])
                continue;
            if(consecutive>k) continue;    
            if (u == n - 1)
                return dis[u][consecutive];

            for (auto& [v, w] : adj[u]) {
                int newconsecutive ;
                if (labels[u] == labels[v]) {
                    newconsecutive = consecutive + 1;
                }
                else{
                    newconsecutive  = 1;
                }
                if ( newconsecutive <= k && dis[v][newconsecutive] > d + w) {
                    dis[v][newconsecutive] = d + w;
                    pq.push({d+w, v, newconsecutive});
                }
            }
        }

        return -1;
    }
};