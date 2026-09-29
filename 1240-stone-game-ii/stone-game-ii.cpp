class Solution {
    vector<int> piles;
    int n;
    int dp[105][105][2];

    int solve(int idx, int m, int turn) {

        if (idx >= n) {
            return 0;
        }
        if (dp[idx][m][turn] != -1) {
            return dp[idx][m][turn];
        }
        int ans = turn ? -1e9 : 1e9;
        int stones = 0;

        for (int i = 1; i <= 2 * m && i + idx <= n; i++) {

            stones += piles[idx + i - 1];
            if (turn) {
                ans = max(solve(idx + i, max(m, i), turn ^ 1) + stones, ans);
            } else {
                ans = min(solve(idx + i, max(m, i), turn ^ 1), ans);
            }
        }

        return dp[idx][m][turn] = ans;
    }

public:
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        this->piles = piles;
        memset(dp, -1, sizeof(dp));
        return solve(0, 1, 1);
    }
};