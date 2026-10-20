class Solution {
    using ll = long long;
    vector<int> nums;
    
    bool ispossible(int mid, int maxop) {
        ll cnt = 0;
        for (int num : nums) {
            int x = (num-1) / mid ;

            cnt += x;
        }

        return cnt <= maxop;
    }

public:
    int minimumSize(vector<int>& nums, int maxOperations) {

        this->nums = nums;
        int ans = 0;
        int low = 1, high = *max_element(nums.begin(), nums.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (ispossible(mid, maxOperations)) {
                ans = mid;
                high = mid - 1;

            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};