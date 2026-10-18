class Solution {

    int n;
    vector<int> nums;
    int dp[255][255];

    int solve(int idx, int k) {
        if(k == 0){
            return idx == n?0:INT_MAX;
        }
        if(n-idx<k){
            return INT_MAX;
        }
        if (idx >= n) {
            return  INT_MAX;
        }
        if (dp[idx][k] != -1) {
            return dp[idx][k];
        }
        int ans = INT_MAX;
        int currxor = 0;

        for (int j = idx; j < n; j++) {
            currxor ^= nums[j];
            int temp = max(currxor, solve(j + 1, k - 1));
            ans = min(ans, temp);
        }

        return dp[idx][k] = ans;
    }

public:
    int minXor(vector<int>& nums, int k) {

        this->nums = nums;
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, k);
    }
};