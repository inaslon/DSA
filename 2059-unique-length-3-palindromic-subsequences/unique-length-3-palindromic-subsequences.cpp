class Solution {
public:
    int countPalindromicSubsequence(string s) {

        int n = s.length();
        vector<int> first(26, -1);
        for (int a = 0; a < 26; a++) {
            for (int i = 0; i < n; i++) {
                if (s[i] - 'a' == a) {
                    first[a] = i;
                    break;
                }
            }
        }
        vector<int> last(26, -1);
        for (int a = 0; a < 26; a++) {
            for (int i = n - 1; i >= 0; i--) {
                if (s[i] - 'a' == a) {
                    last[a] = i;
                    break;
                }
            }
        }

        int ans = 0;
        for (int a = 0; a < 26; a++) {
            int l = first[a];
            int r = last[a];
            if (l == -1 || r == -1 || l == r)
                continue;
            unordered_set<int> st;
            for (int i = l + 1; i < r; i++) {
                st.insert(s[i] - 'a');
            }

            ans += st.size();
        }

        return ans;
    }
};