class Solution {
public:
    string removeKdigits(string num, int k) {

        string st;
        int n = num.size();
        if (n == k) {
            return "0";
        }

        for (int i = 0; i < n; i++) {

            while (!st.empty() && k > 0 && st.back() > num[i]) {
                st.pop_back();
                k--;
            }

            if (st.length() > 0 || num[i] != '0') {

                st.push_back(num[i]);
            }
        }

        while (!st.empty() && k--) {
            st.pop_back();
        }

        return st.empty() ? "0" : st;
    }
};