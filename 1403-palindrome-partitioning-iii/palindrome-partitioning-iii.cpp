class Solution {
    string s;
    int n;
    int dp[105][105];
    int palindromecost(int l, int r) {
        int cost = 0;
        int i = l, j = r;
        while (i < j) {
            if (s[i] != s[j])
                cost++;
            i++;
            j--;
        }

        return cost;
    }

    int solve(int idx, int k) {
        if (k == 0) {
            if (idx == n)
                return 0;
            return 1e9;
        }

        if (idx >= n)
            return 1e9;
        if (dp[idx][k] != -1)
            return dp[idx][k];
        int ans = 1e9;

        for (int j = idx; j < n; j++) {

            int temp = palindromecost(idx, j) + solve(j + 1, k - 1);

            ans = min(ans, temp);
        }

        return dp[idx][k] = ans;
    }

public:
    int palindromePartition(string s, int k) {

        n = s.length();
        this->s = s;
        memset(dp, -1, sizeof(dp));
        return solve(0, k);
    }
};