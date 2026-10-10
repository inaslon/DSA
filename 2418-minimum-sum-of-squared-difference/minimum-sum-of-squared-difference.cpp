class Solution {
    using ll = long long;

public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                               int k2) {
        int n = nums1.size();
        vector<int> nums(n, 0);

        for (int i = 0; i < n; i++) {
            nums[i] = abs(nums1[i] - nums2[i]);
        }

        // sort(nums.begin(),nums.end());
        int k = k1 + k2;

        vector<int> arr(1e5 + 1, 0);

        for (auto num : nums) {
            arr[num]++;
        }

        int m = arr.size();
        for (int i = m - 1; i > 0; i--) {
            if (arr[i] == 0)
                continue;
            int change = min(k, arr[i]);
            arr[i] -= change;
            arr[i - 1] += change;
            k -= change;
        }

        ll ans = 0;
        for (int i = 0; i < m; i++) {
            ans += 1LL * i * i * arr[i];
        }

        return ans;
    }
};