class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {

        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for (auto& vec : invocations) {
            int u = vec[0];
            int v = vec[1];

            indegree[v]++;
            adj[u].push_back(v);
        }

        queue<int> q;
        vector<bool> infected(n, false);

        q.push(k);
        infected[k] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto& v : adj[u]) {

                indegree[v]--;
                if (!infected[v]) {
                    infected[v] = true;
                    q.push(v);
                }
            }
        }
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (infected[i] && indegree[i] != 0) {
                ok = false;
                break;
            }
        }
        vector<int> ans;
        if (ok) {
            for (int i = 0; i < n; i++) {
                if (!infected[i]) {
                    ans.push_back(i);
                }
            }
        } else {

            for (int i = 0; i < n; i++) {

                ans.push_back(i);
            }
        }

        return ans;
    }
};