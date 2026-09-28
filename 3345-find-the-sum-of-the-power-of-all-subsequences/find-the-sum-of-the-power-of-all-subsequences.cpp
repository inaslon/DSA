class Solution {
    const int mod = 1e9 + 7;
    int n;
    vector<int> a;
    using ll = long long;

    ll pow(ll n, ll x) {
        ll ans = 1;

        while (x > 0) {
            if (x % 2 != 0) {
                ans = ans * n % mod;
            }

            n = (n * n % mod);
            x = x / 2;
        }

        return ans;
    }

    int dp[103][103][103];

    int solve(int idx, int len, int sum) {

        if (idx == n) {

            if (sum == 0) {
                return pow(2, n - len);
            }

            return 0;
        }

        if (dp[idx][len][sum] != -1) {
            return dp[idx][len][sum];
        }

        int skip = solve(idx + 1, len, sum);
        int take = 0;
        if (sum - a[idx] >= 0) {
            take = solve(idx + 1, len + 1, sum - a[idx]);
        }

        return dp[idx][len][sum] = (skip + take) % mod;
    }

public:
    int sumOfPower(vector<int>& nums, int k) {
        n = nums.size();
        a = nums;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, k);
    }
};