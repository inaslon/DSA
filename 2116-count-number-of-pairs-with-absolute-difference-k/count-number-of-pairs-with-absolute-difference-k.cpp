class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int ans = 0;
        for (int i = 0; i < n; i++) {

            int t1 = nums[i] - k;
            int t2 = nums[i] + k;

            if (mp.count(t1)) {
                ans += mp[t1];
            }

            if (mp.count(t2)) {
                ans += mp[t2];
            }

            mp[nums[i]]++;
        }

        return ans;
    }
};