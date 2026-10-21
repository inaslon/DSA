class Solution {
public:
    int minOperations(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int m = nums.size();
        int maxconsecutive = 0;

        int l = 0;
        for (int r = 0; r < m; r++) {
            while (nums[r] - nums[l] >= n) {
                l++;
            }
            maxconsecutive = max(maxconsecutive, r - l + 1);
        }

        return n - maxconsecutive;
    }
};