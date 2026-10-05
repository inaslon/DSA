class Solution {
public:
    int scoreOfParentheses(string s) {
        int open = 0;
        bool firstclose = false;
        int ans = 0;
        for (char c : s) {

            if (c == '(') {
                open++;
                firstclose = false;
            }

            else if (c == ')' && !firstclose) {
                ans += pow(2, open - 1);
                firstclose = true;
                open--;
            }

            else {
                open--;
            }
        }

        return ans;
    }
};