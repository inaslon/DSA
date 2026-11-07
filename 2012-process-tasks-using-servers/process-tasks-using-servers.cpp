class Solution {
    using p = pair<int, int>;
    using t = tuple<long long, int, int>;

public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        priority_queue<p, vector<p>, greater<p>> running;
        priority_queue<t, vector<t>, greater<t>> waiting;
        int n = servers.size();
        for (int i = 0; i < n; i++) {
            running.push({servers[i], i});
        }

        int m = tasks.size();
        vector<int> ans(m, -1);

        long long time = 0;

        for (int i = 0; i < m; i++) {
            
            time = max(time,(long long)i);
            int t = tasks[i];


            // remove all waiting servers where time>= waiting time;
            while (!waiting.empty() && get<0>(waiting.top()) <= time) {
                auto [ti, w, idx] = waiting.top();

                running.push({w, idx});
                waiting.pop();
            }

            // running empty

            if (running.empty()) {

                time = get<0>(waiting.top());

                while (!waiting.empty() && get<0>(waiting.top()) == time) {
                    auto [ti,w,idx] = waiting.top();
                    waiting.pop();
                    running.push({w,idx});
                }
            }

            auto [w, idx] = running.top();
            running.pop();
            waiting.push({time + t, w, idx});
          
            ans[i] = idx;
        }

        return ans;
    }
};