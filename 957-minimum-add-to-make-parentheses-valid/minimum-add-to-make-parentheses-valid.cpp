class Solution {
public:
    int minAddToMakeValid(string s) {

        int open = 0;
        int close = 0;
        int ans = 0;
        stack<char> st;
        for (auto ch : s) {
            if (ch == '(') {
                st.push('(');
            } else {
              if(!st.empty()){
                st.pop();
              }
              else{
                close++;
              }
                           }

        }

        return st.size()+close;
    }
};