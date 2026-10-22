class Solution {
    using ll = long long;

public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        ll currsum = 0;
        ll ans = 0;
        unordered_set<int> st;

        int l = 0;
        for (int r = 0; r < n; r++) {
            currsum += nums[r];
            while (st.count(nums[r]) || r-l+1>k) {
                st.erase(st.find(nums[l]));
                currsum -= nums[l];
                l++;
            }

            st.insert(nums[r]);

            if (r - l + 1 == k) {
                ans = max(ans, currsum);
            }
        }
        return ans;
    }
};