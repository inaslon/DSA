class Solution {
public:
    string reverseParentheses(string s) {

        stack<int> st;
        int n = s.length();
        string ss;

        for (char c : s) {
            if (c == '(') {
                st.push(ss.size());
            } else if (c == ')') {
                int idx = st.top();

                st.pop();

                reverse(ss.begin() + idx, ss.end());
            } else {
                ss.push_back(c);
            }
        }

        return ss;
    }
};