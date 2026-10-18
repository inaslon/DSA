class Solution {
    vector<int> arr;
    int n;

    int dp[305][15];
    int solve(int idx, int d) {
        if (d == 0) {
            return idx == n ? 0 : 1e9;
        }

        if (n - idx < d)
            return 1e9;

        if (dp[idx][d] != -1) {
            return dp[idx][d];
        }

        int ans = 1e9;
        int maxjob = -1e9;

        for (int k = idx; k < n; k++) {
            maxjob = max(maxjob, arr[k]);
            int temp = maxjob + solve(k + 1, d - 1);
            ans = min(ans, temp);
        }

        return dp[idx][d] = ans;
    }

public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        arr = jobDifficulty;
        n = arr.size();
        memset(dp, -1, sizeof(dp));
        int ans = solve(0,d);
        return ans == 1e9?-1:ans;
    }
};