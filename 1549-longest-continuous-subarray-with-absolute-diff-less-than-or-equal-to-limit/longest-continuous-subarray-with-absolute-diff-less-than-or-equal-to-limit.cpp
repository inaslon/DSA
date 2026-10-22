class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        int n = nums.size();
        deque<int> mx, mn;
        int ans = 0;
        int l = 0;

        for (int r = 0; r < n; r++) {

            while (!mx.empty() && nums[mx.back()] < nums[r]) {
                mx.pop_back();
            }
            mx.push_back(r);

            while (!mn.empty() && nums[mn.back()] > nums[r]) {
                mn.pop_back();
            }
            mn.push_back(r);

            while (nums[mx.front()] - nums[mn.front()] > limit) {

                if (mx.front() == l) {
                    mx.pop_front();
                }

                if (mn.front() == l) {
                    mn.pop_front();
                }

                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};