class Solution {
public:
    string removeKdigits(string num, int k) {

        string st;
        int n = num.size();
        if(n == k){
            return "0";
        }

        for (int i = 0; i < n; i++) {

            while (!st.empty() && k > 0 && st.back() > num[i]) {
                st.pop_back();
                k--;
            }

            st.push_back(num[i]);
        }

        while(k--){
            st.pop_back();
        }

        int i = 0;
        while (i < st.size() && st[i] == '0') {
            i++;
        }

        st = st.substr(i);

        return st.empty() ? "0" : st;
    }
};