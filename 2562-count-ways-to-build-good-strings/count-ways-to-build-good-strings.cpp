class Solution {
    const long long MOD = 1000000007LL;
    int dp[100005];
    int mnlen, mxlen, onelen, zerolen;
    int solve(int len) {
        if (len > mxlen)
            return 0;

        if (dp[len] != -1) {
            return dp[len];
        }
        int ans = 0;
        if (len >= mnlen) {
            ans++;
        }

        int takez = solve(len + zerolen);
        int takeo = solve(len + onelen);

        return dp[len] = (ans + takeo + takez) % MOD;
    }

public:
    int countGoodStrings(int low, int high, int zero, int one) {
        mxlen = high;
        mnlen = low;
        onelen = one;
        zerolen = zero;

        memset(dp, -1, sizeof(dp));
        return solve(0);
    }
};