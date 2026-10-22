class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        multiset<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
            if (st.size() > k) {
                st.erase(st.find(nums[i - k]));
            }
            if (st.size() == k) {
                ans.push_back(*st.rbegin());
            }
        }
        return ans;
    }
};