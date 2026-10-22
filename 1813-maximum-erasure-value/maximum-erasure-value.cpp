class Solution {

public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int currsum = 0;
        int ans = 0;
        unordered_set<int> st;
        
        int l =0;
        for(int r = 0;r<n;r++){
            currsum += nums[r];
            while(st.count(nums[r])){
                st.erase(st.find(nums[l]));
                currsum -=nums[l];
                l++;
            }

            st.insert(nums[r]);

            ans = max(ans,currsum);
        }
        return ans;
    }
};