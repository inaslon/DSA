class Solution {
    int n;
    int dp[105][105];
    bool solve(int idx, int diff ,string& s) {
        if (diff<0) {
            return false;
        }
        if (idx == n) {
            return diff == 0;
        }
        if (dp[idx][diff] != -1) {
            return dp[idx][diff];
        }
        if (s[idx] == '(') {
            return dp[idx][diff] = solve(idx + 1, diff+1, s);
        }

        if (s[idx] == ')') {
            return dp[idx][diff] = solve(idx + 1, diff-1, s);
        }

        if (s[idx] == '*') {
            return dp[idx][diff] = (solve(idx + 1, diff+1, s) ||
                                           solve(idx + 1,diff-1, s) ||
                                           solve(idx + 1, diff , s));
        }

        return dp[idx][diff] = false;
    }

public:
    bool checkValidString(string s) {
        n = s.length();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, s);
    }
};