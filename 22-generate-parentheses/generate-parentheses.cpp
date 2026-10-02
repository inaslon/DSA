class Solution {

    void solve(int n, int m, string temp, vector<string>& ans) {
        if (n == 0 && m == 0) {
            ans.push_back(temp);
            return;
        }

        if (n > 0) {
            temp.push_back('(');
            solve(n - 1, m, temp, ans);
            temp.pop_back();
        }
        if (m > n) {
            temp.push_back(')');
            solve(n, m - 1, temp, ans);
            temp.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {

        vector<string> ans;
        solve(n, n, "", ans);
        return ans;
    }
};