class Solution {
    int helper(vector<int>& nums, int k){
         int l = 0;
        int ans = 0;
        int cnt = 0;
         for (int r = 0; r < nums.size(); r++) {
            if (nums[r] % 2 != 0) {
                cnt++;
            }

            while (cnt > k) {
                if (nums[l] % 2 != 0) {
                    cnt--;
                }
                l++;
            }

            ans += r - l + 1;
        }

        return ans;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

       

        return helper(nums,k) - helper(nums,k-1);
    }
};