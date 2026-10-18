class Solution {
    int n;
    vector<int> nums;
    int dp[1005][1005];
    int solve(int idx, int k) {
        if (k == 0) {
            return idx == n ? 0 : 1e9;
        }

        if (n - idx < k) {
            return 1e9;
        }

        if (dp[idx][k] != -1) {
            return dp[idx][k];
        }

        int ans = 1e9;
        int currsum = 0;

        for (int j = idx; j < n; j++) {

            currsum += nums[j];
            int rem = solve(j + 1, k - 1);

            ans = min(ans, max(currsum, rem));
        }

        return dp[idx][k] = ans;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        this->nums = nums;
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, k);
    }
};