
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = a.length();
        int m = b.length();

        int k = (m + n - 1) / n;

        string s;
        for (int i = 0; i < k + 1; i++) {
            s += a;
        }

        long long mod = 1000000007;
        long long p = 31;

        long long target = 0;
        long long hash = 0;
        long long power = 1;

        for (int i = 0; i < m; i++) {
            target = (target * p + (b[i] - 'a' + 1)) % mod;
            hash = (hash * p + (s[i] - 'a' + 1)) % mod;

            if (i < m - 1) {
                power = (power * p) % mod;
            }
        }

        for (int i = 0; i + m <= (int)s.length(); i++) {
            if (hash == target) {
                if (s.substr(i, m) == b) {
                    return (i + m + n - 1) / n;
                }
            }

            if (i + m < (int)s.length()) {
                hash = (hash - ((s[i] - 'a' + 1) * power) % mod + mod) % mod;
                hash = (hash * p + (s[i + m] - 'a' + 1)) % mod;
            }
        }

        return -1;
    }
};
