class Solution {
    using ll = long long;
    const int mod = 1e9 + 7;

public:
    int countPalindromes(string s) {
        int n = s.length();
        vector<vector<vector<ll>>> pref(n,
                                        vector<vector<ll>>(10, vector<ll>(10)));
        vector<vector<vector<ll>>> suf(n,
                                        vector<vector<ll>>(10, vector<ll>(10)));

        ll cnt[10] = {};
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                pref[i] = pref[i - 1];
            }

            int x = s[i] - '0';

            for (int a = 0; a < 10; a++) {
                pref[i][a][x] += cnt[a];
            }

            cnt[x]++;
        }

        for (int i = 0; i < 10; i++) {
            cnt[i] = 0;
        }

        for (int i = n - 1; i >= 0; i--) {
            if (i + 1 < n) {
                suf[i] = suf[i + 1];
            }

            int x = s[i] - '0';

            for (int a = 0; a < 10; a++) {
                suf[i][x][a] += cnt[a];
            }

            cnt[x]++;
        }

        ll ans = 0;

        for (int i = 0; i < n; i++) {
            for (int a = 0; a < 10; a++) {
                for (int b = 0; b < 10; b++) {
                    ll left = 0, right = 0;
                    if (i > 0) {
                        left = pref[i - 1][a][b];
                    }
                    if (i + 1 < n) {
                        right = suf[i + 1][b][a];
                    }

                    ans = (ans + left * right) % mod;
                }
            }
        }

        return ans;
    }
};