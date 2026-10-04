class Solution {
    int n;
    int dp[105][105][105];
    bool solve(int idx, int open, int close, string& s) {
        if (close > open) {
            return false;
        }
        if (idx == n) {
            return open == close;
        }
        if (dp[idx][open][close] != -1) {
            return dp[idx][open][close];
        }
        if (s[idx] == '(') {
            return dp[idx][open][close] = solve(idx + 1, open + 1, close, s);
        }

        if (s[idx] == ')') {
            return dp[idx][open][close] = solve(idx + 1, open, close + 1, s);
        }

        if (s[idx] == '*') {
            return dp[idx][open][close] = (solve(idx + 1, open + 1, close, s) ||
                                           solve(idx + 1, open, close + 1, s) ||
                                           solve(idx + 1, open, close, s));
        }

        return dp[idx][open][close] = false;
    }

public:
    bool checkValidString(string s) {
        n = s.length();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, s);
    }
};