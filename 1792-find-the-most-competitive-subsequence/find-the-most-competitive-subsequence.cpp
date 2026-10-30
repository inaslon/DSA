class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> st;

        int kk = n - k;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && st.back() > nums[i] && kk > 0) {
                st.pop_back();
                kk--;
            }

            st.push_back(nums[i]);
        }

        // vector<int> ans(st.begin(), st.begin() + k);
        st.resize(k);

        return st;
    }
};