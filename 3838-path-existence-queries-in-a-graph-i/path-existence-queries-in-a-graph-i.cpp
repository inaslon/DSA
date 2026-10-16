class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {

        vector<int> comp(n, 0);
        int compno = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] > maxDiff) {
                compno++;
            }
            comp[i] = compno;
        }

        vector<bool> ans(queries.size(), false);
        for (int i = 0; i < queries.size(); i++) {
            if (comp[queries[i][0]] == comp[queries[i][1]]) {
                ans[i] = true;
            }
        }

        return ans;
    }
};