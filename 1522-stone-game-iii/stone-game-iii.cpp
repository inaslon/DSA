class Solution {
    int n;
    vector<int> piles;
    int dp[50005][2];
    bool vis[50005][2];
    int solve(int idx, int turn) {

        if (idx >= n) {
            return 0;
        }
        if (vis[idx][turn]) {
            return dp[idx][turn];
        }
        vis[idx][turn] = true;
        int ans = turn ? -1e9 : 1e9;
        int stones = 0;

        for (int i = 1; i <= 3 && i + idx <= n; i++) {

            stones += piles[idx + i - 1];
            if (turn) {
                ans = max(solve(idx + i, turn ^ 1) + stones, ans);
            } else {
                ans = min(solve(idx + i, turn ^ 1) - stones, ans);
            }
        }

        return dp[idx][turn] = ans;
    }

public:
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        piles = stoneValue;
        memset(dp, 0, sizeof(dp));
        memset(vis,false,sizeof(vis));
        int ans = solve(0, 1);

        if (ans == 0) {
            return "Tie";
        } else if (ans > 0) {
            return "Alice";
        } else {
            return "Bob";
        }
    }
};