class Solution {
    using ll = long long;
    using p = pair<ll, int>;

public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        set<int> st;
        priority_queue<p, vector<p>, greater<p>> waiting;

        for (int i = 0; i < k; i++) {
            st.insert(i);
        }

        unordered_map<int, int> mp;

        int busy = 0;

        int n = arrival.size();
        for (int i = 0; i < n; i++) {
            int a = arrival[i];
            int l = load[i];

            while (!waiting.empty() && waiting.top().first <= a) {
                auto [t, ser] = waiting.top();
                st.insert(ser);
                waiting.pop();
            }

            if (st.empty()) {
                continue;
            }

            int ser = -1;
            int target_server = i % k;
            
            auto it = st.lower_bound(target_server);

            if(it == st.end()){
                it = st.begin();
            }

            ser = *it;
            st.erase(it);
            mp[ser]++;
            waiting.push({a + l, ser});
            if (busy < mp[ser]) {
                busy = mp[ser];
            }
        }

        vector<int> ans;

        for (auto& [ser, freq] : mp) {
            if (freq == busy) {
                ans.push_back(ser);
            }
        }

        return ans;
    }
};