class Solution {
    int n;
    vector<int> piles;
    int dp[50005];

    int solve(int idx) {

        if (idx >= n) {
            return 0;
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }

        int ans = -1e9;
        int stones = 0;

        for (int i = 1; i <= 3 && i + idx <= n; i++) {

            stones += piles[idx + i - 1];

            ans = max(-solve(idx + i) + stones, ans);
        }

        return dp[idx] = ans;
    }

public:
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        piles = stoneValue;
        memset(dp, -1, sizeof(dp));

        int ans = solve(0);

        if (ans == 0) {
            return "Tie";
        } else if (ans > 0) {
            return "Alice";
        } else {
            return "Bob";
        }
    }
};