class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;

        sort(nums.begin(),nums.end());

        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        int m = nums.size();

        
        int ans = 1;
        int currlen = 1;
        for(int r = 1;r<m;r++){
            if(nums[r]- nums[r-1] == 1){
                currlen++;
            }
            else{
                currlen = 1;
            }

            ans = max(ans,currlen);
        }

        return ans;
    }
};