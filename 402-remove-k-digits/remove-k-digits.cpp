class Solution {
public:
    string removeKdigits(string num, int k) {

        int n = num.size();

        string s;
        int len = n-k;

        for (int i = 0; i < n; i++) {
            int d = num[i] - '0';

            while (!s.empty() && s.back() - '0' > d && k > 0) {
                s.pop_back();
                k--;
            }

            s.push_back(num[i]);
        }

        while (k > 0) {
            s.pop_back();
            k--;
        }

        // s.resize(len);
        int i = 0;
        while (i < s.size() && s[i] == '0') {
            i++;
        }

        s.erase(0, i);

        if (s.empty())
            return "0";

        return s;
    }
};