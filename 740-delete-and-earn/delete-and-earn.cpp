class Solution {
    int n = 10001;
    vector<int> a;
    int dp[10005];
    int solve(int idx) {
        if (idx >= n)
            return 0;
        if (dp[idx] != -1) {
            return dp[idx];
        }
        int skip = solve(idx + 1);

        int take = a[idx] + solve(idx + 2);

        return dp[idx] = max(take, skip);
    }

public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        };

        vector<int> newarr(10001, 0);
        for (int i = 1; i <= 10000; i++) {
            newarr[i] = mp[i] * i;
        }

        a = newarr;
        memset(dp, -1, sizeof(dp));
        return solve(1);
    }
};