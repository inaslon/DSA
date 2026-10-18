class Solution {
    string s;
    int n;
    int dp[2004][4];
    bool ispalindrome(int l, int r) {
        int i = l, j = r;
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
    bool solve(int idx, int p) {
        if (p == 0) {
            return idx == n;
        }

        if (n - idx < p)
            return false;
        
        if(dp[idx][p] !=-1){
            return dp[idx][p];
        }
        bool ans = false;

        for (int j = idx; j < n; j++) {

            if (ispalindrome(idx, j)) {

                ans = ans || solve(j + 1, p - 1);
            }
        }

        return dp[idx][p] = ans;
    }

public:
    bool checkPartitioning(string s) {
        this->s = s;
        n = s.size();
        memset(dp,-1,sizeof(dp));
        return solve(0, 3);
    }
};