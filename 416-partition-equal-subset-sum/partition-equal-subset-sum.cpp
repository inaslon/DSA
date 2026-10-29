class Solution {

    int n;
    vector<int> nums;

    int sum ;

    vector<vector<int>> dp;

    bool solve(int idx, int diff) {
        if (idx == n) {
            return diff == 0;
        }

        if (dp[idx][diff+sum] != -1)
            return dp[idx][diff+sum];

        bool s1 = solve(idx + 1, diff + nums[idx]);
        bool s2 = solve(idx + 1, diff - nums[idx]);

        return dp[idx][diff+sum] = s1 || s2;
    }

public:
    bool canPartition(vector<int>& nums) {

    sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 != 0)
            return 0;
        n = nums.size();

        this->nums = nums;

        dp.assign(n + 1, vector<int>(2*sum+1, -1));
        return solve(0, 0);
    }
};