class Solution {
    int n;
    vector<int> piles;
    int dp[50005][2];
  
    int solve(int idx, int turn) {

        if (idx >= n) {
            return 0;
        }
        if (dp[idx][turn] !=-1) {
            return dp[idx][turn];
        }
    
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
        memset(dp, -1, sizeof(dp));
       
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