class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        int n = nums.size();
        int l = 0;
        int ans = 1;
        multiset<int> st;
        for(int r = 0;r<n;r++){
            st.insert(nums[r]);
            while(*st.rbegin()- *st.begin()>limit){
                st.erase(st.find(nums[l]));
                l++;
            }

            ans = max(ans,r-l+1);
        }

        return ans;
    }
};