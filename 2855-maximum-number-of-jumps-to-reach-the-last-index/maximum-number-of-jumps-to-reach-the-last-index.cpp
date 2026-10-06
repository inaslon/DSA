class Solution {
    int n;
    int target;
    vector<int> nums;
    int dp[1004];
    int solve(int idx) {
        if (idx == n - 1)
            return 0;
        if (dp[idx] != -2) {
            return dp[idx];
        }
        int ans = -1;

        for (int i = idx + 1; i < n; i++) {
            if (nums[i] - nums[idx] <= target &&
                nums[i] - nums[idx] >= -target) {
                int x = solve(i);

                if (x != -1) {
                    ans = max(ans, 1 + x);
                }
            }
        }

        return dp[idx] = ans;
    }

public:
    int maximumJumps(vector<int>& nums, int target) {
        n = nums.size();
        this->target = target;
        this->nums = nums;
        fill(dp, dp + n, -2);
        return solve(0);
    }
};