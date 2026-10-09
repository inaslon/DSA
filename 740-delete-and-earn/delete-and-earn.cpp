class Solution {
    int n;
    vector<int> a, dp;

    int solve(int idx) {
        if (idx >= n)
            return 0;
        if (dp[idx] != -1) {
            return dp[idx];
        }
        int skip = solve(idx + 1);
        int next =
            upper_bound(a.begin() + idx, a.end(), a[idx] + 1) - a.begin();
        int ni = upper_bound(a.begin() + idx, a.end(), a[idx]) - a.begin();
        int freq = ni - idx;
         int take = a[idx] * freq + solve(next);

        return dp[idx] = max(take, skip);
    }

public:
    int deleteAndEarn(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        a = nums;
        n = a.size();
        dp.assign(n, -1);
        return solve(0);
    }
};