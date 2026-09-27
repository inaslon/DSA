class Solution {
    using ll = long long;
    vector<vector<int>> meets;
    vector<ll> sufmax;
    int n;

    int nextidx(int idx) {
        int low = idx + 1, high = n - 1;
        int ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (meets[mid][0] >= meets[idx][1]) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }

    vector<ll> dp;

    ll solve(int idx) {
        if (idx >= n)
            return 0;
        if (dp[idx] != -1) {
            return dp[idx];
        }

        int next = nextidx(idx);
        ll ans = meets[idx][2];
        if (next != -1) {
            ans = max(ans, +(ll)meets[idx][2] - meets[idx][1] + sufmax[next]);
        }

        return dp[idx] = ans;
    }

public:
    long long maxEarnings(vector<vector<int>>& meetings) {

        sort(meetings.begin(), meetings.end(),
             [](auto& a, auto& b) { return a[0] < b[0]; });

        meets = meetings;
        n = meets.size();
        dp.assign(n + 1, -1);
        sufmax.assign(n + 1, LLONG_MIN);
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = -1;
            solve(i);
            sufmax[i] = (ll)meets[i][0] + dp[i];

            if (i + 1 < n) {
                sufmax[i] = max(sufmax[i], sufmax[i + 1]);
            }
        }

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};