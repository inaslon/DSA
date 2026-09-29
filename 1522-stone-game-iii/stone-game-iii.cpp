class Solution {
    int n;
    vector<int> piles;
   

public:
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        piles = stoneValue;
        
        vector<int> dp(n + 1, -1e9);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) {

            int stones = 0;

            for (int x = 1; x <= 3 && i + x <= n; x++) {
                stones += piles[i + x - 1];
                dp[i] = max(-dp[i + x] + stones, dp[i]);
            }
        }
       int ans = dp[0];
        if (ans == 0) {
            return "Tie";
        } else if (ans > 0) {
            return "Alice";
        } else {
            return "Bob";
        }
    }
};