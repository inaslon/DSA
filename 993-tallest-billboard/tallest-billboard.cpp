class Solution {
    vector<int> a;
    int n;
    int dp[22][10004];
    int solve(int idx, int diff) {
        if (idx == n) {

            if (diff == 0) {
                return 0;
            }

            return -1e9;
        }

        if (dp[idx][diff+5000] != -1) {
            return dp[idx][diff+5000];
        }

        int take1 = a[idx] + solve(idx + 1, diff + a[idx]);
        int take2 = a[idx] + solve(idx + 1, diff - a[idx]);

        int skip = solve(idx + 1, diff);

        return dp[idx][diff+5000] = max({take1, take2, skip});
    }

public:
    int tallestBillboard(vector<int>& rods) {
        a = rods;
        n = a.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0) / 2;
    }
};