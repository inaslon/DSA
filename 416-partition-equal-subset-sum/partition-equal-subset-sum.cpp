class Solution {

    int n;
    vector<int> nums;

    int sum;

    vector<vector<int>> dp;

    bool solve(int idx, int target) {
        if (target < 0)
            return false;
        if (idx == n) {
            return target == 0;
        }

        if (dp[idx][target] != -1)
            return dp[idx][target];

        bool take = solve(idx + 1, target - nums[idx]);
        bool skip = solve(idx + 1, target);

        return dp[idx][target] = take || skip;
    }

public:
    bool canPartition(vector<int>& nums) {

        sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 != 0)
            return 0;
        n = nums.size();

        this->nums = nums;

        dp.assign(n + 1, vector<int>(sum / 2 + 1, -1));
        return solve(0, sum / 2);
    }
};