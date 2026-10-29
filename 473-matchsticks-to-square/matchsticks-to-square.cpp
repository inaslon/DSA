class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {

        // so the problem is basically can i divide the array into 4 parts
        // having same sum

        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);

        if (sum % 4 != 0)
            return false;

        int target = sum / 4;

        int n = matchsticks.size();
        vector<int> dp((1 << n), -1);
        dp[0] = 0;

        for (int mask = 0; mask < (1 << n); mask++) {
            if (dp[mask] == -1) {
                continue;
            }

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i))
                    continue;

                int newsum = matchsticks[i] + dp[mask];
                if (newsum > target)
                    continue;

                int newmask = mask | (1 << i);

                dp[newmask] = newsum % target;
            }
        }

        int fullmask = (1<<n) -1;
        return dp[fullmask] == 0;
    }
};