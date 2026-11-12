class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        int len = 1;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {

            if (nums[i] < nums[i + 1]) {

                int j = i;
                while (j + 1 < n && nums[j] < nums[j + 1]) {
                    j++;
                }

                len = max(len, j - i + 1);
                i = j ;
            }
        }

        for (int i = 0; i < n - 1; i++) {

            if (nums[i] > nums[i + 1]) {

                int j = i;
                while (j + 1 < n && nums[j] > nums[j + 1]) {
                    j++;
                }

                len = max(len, j - i + 1);
                i = j ;
            }
        }
        return len;
    }
};