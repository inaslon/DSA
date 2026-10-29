class Solution {
    int n;
    int target;
    vector<int> dp;
    bool solve(int mask, int sum) {
        if (dp[mask] != -1) {
            return dp[mask];
        }
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i))
                continue;

            int newmask = mask | (1 << i);

            if (sum + i + 1 >= target) // i+1 number
                return dp[mask] = true;

            if (!solve(newmask, sum + i + 1)) {
                return dp[mask] = true;
            }
        }

        return dp[mask] = false;
    };

public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        n = maxChoosableInteger;
        target = desiredTotal;
        int sum = (n * (n + 1) / 2);
        if (sum < target)
            return false;

        dp.assign((1 << n), -1);

        return solve(0, 0);
    }
};